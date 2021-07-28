#include "Excluder.h"
#include "Utils.h"
#include <cmath>
#include <cassert>

void Excluder::Init(const AARectangle& rect, bool reverseNormals)
{
	mAARect = rect;
	mReverseNormals = reverseNormals;
	SetupEdges();
}

bool Excluder::HasCollided(const AARectangle& rect, BoundaryEdge& edge) const
{
	if(mAARect.Intersects(rect))
	{
		float yMin = mAARect.GetTopLeftPt().GetY() >= (rect.GetTopLeftPt().GetY()) ? mAARect.GetTopLeftPt().GetY() : rect.GetTopLeftPt().GetY();
		float yMax = mAARect.GetBottomRightPt().GetY() <= rect.GetBottomRightPt().GetY() ? mAARect.GetBottomRightPt().GetY() : rect.GetBottomRightPt().GetY();

		float ySize = yMax - yMin;

		float xMin = mAARect.GetTopLeftPt().GetX() >= rect.GetTopLeftPt().GetX() ? mAARect.GetTopLeftPt().GetX() : rect.GetTopLeftPt().GetX();
		float xMax = mAARect.GetBottomRightPt().GetX() <= rect.GetBottomRightPt().GetX() ? mAARect.GetBottomRightPt().GetX() : rect.GetBottomRightPt().GetX();

		float xSize = xMax - xMin;

		if(xSize > ySize)
		{
			if(rect.GetCenterPoint().GetY() > mAARect.GetCenterPoint().GetY())
			{
				edge = mEdges[BOTTOM_EDGE];
			}
			else
			{
				edge = mEdges[TOP_EDGE];
			}
		}
		else
		{
			if(rect.GetCenterPoint().GetX() < mAARect.GetCenterPoint().GetX())
			{
				edge = mEdges[LEFT_EDGE];
			}
			else
			{
				edge = mEdges[RIGHT_EDGE];
			}
		}

		return true;
	}

	return false;
}

Vec2D Excluder::GetCollisionOffset(const AARectangle& rect) const
{
	BoundaryEdge edge;
	Vec2D offset = Vec2D::Zero;

	if(HasCollided(rect, edge))
	{
		float yMin = mAARect.GetTopLeftPt().GetY() >= (rect.GetTopLeftPt().GetY()) ? mAARect.GetTopLeftPt().GetY() : rect.GetTopLeftPt().GetY();
		float yMax = mAARect.GetBottomRightPt().GetY() <= rect.GetBottomRightPt().GetY() ? mAARect.GetBottomRightPt().GetY() : rect.GetBottomRightPt().GetY();

		float ySize = yMax - yMin;

		float xMin = mAARect.GetTopLeftPt().GetX() >= rect.GetTopLeftPt().GetX() ? mAARect.GetTopLeftPt().GetX() : rect.GetTopLeftPt().GetX();
		float xMax = mAARect.GetBottomRightPt().GetX() <= rect.GetBottomRightPt().GetX() ? mAARect.GetBottomRightPt().GetX() : rect.GetBottomRightPt().GetX();

		float xSize = xMax - xMin;

		if(!IsEqual(edge.normal.GetY(), 0))
		{
			offset = (ySize + 1) * edge.normal;
		}
		else
		{
			offset = (xSize + 1) * edge.normal;
		}
	}

	return offset;
}

void Excluder::MoveBy(const Vec2D& delta)
{
	mAARect.MoveBy(delta);
	SetupEdges();
}

void Excluder::MoveTo(const Vec2D& point)
{
	mAARect.MoveTo(point);
	SetupEdges();
}

const BoundaryEdge& Excluder::GetEdge(EdgeType edge) const
{
	assert(edge != NUM_EDGES);
	return mEdges[edge];
}


void Excluder::SetupEdges()
{
	mEdges[TOP_EDGE].edge = {mAARect.GetTopLeftPt().GetX(), mAARect.GetTopLeftPt().GetY(), mAARect.GetBottomRightPt().GetX(), mAARect.GetTopLeftPt().GetY()};
	mEdges[TOP_EDGE].normal = UP_DIR;

	mEdges[LEFT_EDGE].edge = {mAARect.GetTopLeftPt().GetX(), mAARect.GetTopLeftPt().GetY(), mAARect.GetTopLeftPt().GetX(), mAARect.GetBottomRightPt().GetY()};
	mEdges[LEFT_EDGE].normal = LEFT_DIR;

	mEdges[BOTTOM_EDGE].edge = {mAARect.GetTopLeftPt().GetX(), mAARect.GetBottomRightPt().GetY(), mAARect.GetBottomRightPt().GetX(), mAARect.GetBottomRightPt().GetY()};
	mEdges[BOTTOM_EDGE].normal = DOWN_DIR;

	mEdges[RIGHT_EDGE].edge = {mAARect.GetBottomRightPt().GetX(), mAARect.GetTopLeftPt().GetY(), mAARect.GetBottomRightPt().GetX(), mAARect.GetBottomRightPt().GetY()};
	mEdges[RIGHT_EDGE].normal = RIGHT_DIR;

	if(mReverseNormals)
	{
		for(auto& edge : mEdges)
		{
			edge.normal = -edge.normal;
		}
	}
}
