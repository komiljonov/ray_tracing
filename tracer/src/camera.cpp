#include "camera.h"
#include "ray.h"
#include "math.h"

RT::Camera::Camera()
{
	// The default constructor.
	m_cameraPosition = QBVD	{std::vector<double> {0.0, -10.0, 0.0}};
	m_cameraLookAt = QBVD 	{std::vector<double> {0.0, 0.0, 0.0}};
	m_cameraUp = QBVD 			{std::vector<double> {0.0, 0.0, 1.0}};
	m_cameraLength = 1.0;
	m_cameraHorzSize = 1.0;
	m_cameraAspectRatio = 1.0;
}

void RT::Camera::SetPosition(const QBVD &newPosition)
{
	m_cameraPosition = newPosition;
}

void RT::Camera::SetLookAt(const QBVD &newLookAt)
{
	m_cameraLookAt = newLookAt;
}

void RT::Camera::SetUp(const QBVD &upVector)
{
	m_cameraUp = upVector;
}

void RT::Camera::SetLength(double newLength)
{
	m_cameraLength = newLength;
}

void RT::Camera::SetHorzSize(double newHorzSize)
{
	m_cameraHorzSize = newHorzSize;
}

void RT::Camera::SetAspect(double newAspect)
{
	m_cameraAspectRatio = newAspect;
}

// Method to return the position of the camera.
QBVD RT::Camera::GetPosition()
{
    return m_cameraPosition;
}

// Method to return the look at of the camera.
QBVD RT::Camera::GetLookAt()
{
    return m_cameraLookAt;
}

// Method to return the up vector of the camera.
QBVD RT::Camera::GetUp()
{
    return m_cameraUp;
}

// Method to return the length of the camera.
double RT::Camera::GetLength()
{
    return m_cameraLength;
}

double RT::Camera::GetHorzSize()
{
	return m_cameraHorzSize;
}

double RT::Camera::GetAspect()
{
	return m_cameraAspectRatio;
}

QBVD RT::Camera::GetU()
{
	return m_projectionScreenU;
}

QBVD RT::Camera::GetV()
{
	return m_projectionScreenV;
}

QBVD RT::Camera::GetScreenCentre()
{
	return m_projectionScreenCentre;
}

void RT::Camera::UpdateCameraGeometry()
{
	// First, compute the vector from the camera position to the LookAt position.
	m_alignmentVector = m_cameraLookAt - m_cameraPosition;
	m_alignmentVector.Normalize();

	// Second, compute the alpha and beta unit vectors.
	m_projectionScreenU = QBVD::cross(m_alignmentVector, m_cameraUp);
	m_projectionScreenU.Normalize();
	m_projectionScreenV = QBVD::cross(m_projectionScreenU, m_alignmentVector);
	m_projectionScreenV.Normalize();

	// Thirdly, compute the position of the center point of the screen.
	m_projectionScreenCentre = m_cameraPosition + (m_cameraLength * m_alignmentVector);

	// Modify the U and V vectors to match the size and aspect ratio.
	m_projectionScreenU = m_projectionScreenU * m_cameraHorzSize;
	m_projectionScreenV = m_projectionScreenV * (m_cameraHorzSize / m_cameraAspectRatio);
}

bool RT::Camera::GenerateRay(float proScreenX,float proScreenY, RT::Ray &cameraRay)
{
	// Compute the location of the screen point in world coordinates.
	QBVD screenWorldPart1 = m_projectionScreenCentre + (m_projectionScreenU * proScreenX);
	QBVD screenWorldCoordinate = screenWorldPart1 + (m_projectionScreenV * proScreenY);

	// Use this point along with the camera position to compute the ray.
	// return Ray(m_cameraPosition, screenWorldCoordinate);

	cameraRay.m_point1 = m_cameraPosition;
	cameraRay.m_point2 = screenWorldCoordinate;

	cameraRay.m_lab = screenWorldCoordinate - m_cameraPosition;



	return true;
}
