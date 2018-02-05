#include "stdafx.h"
#include "CppUnitTest.h"
#include "Vector2.h"
#include "Vector3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StaticLibraryTests
{		
	TEST_CLASS(Vector2Test)
	{
	public:
		
		TEST_METHOD(MagnitudeTest_Normal)
		{
			float x = 3, y = 4;
			Assert::AreEqual(::Vector2::Magnitude(x, y), 5.f);
		}

		TEST_METHOD(MagnitudeTest_Negative)
		{
			float x = -3, y = -4;
			Assert::AreEqual(::Vector2::Magnitude(x, y), 5.f);
		}

		TEST_METHOD(MagnitudeTest_Zeroes)
		{
			float x = 0, y = 0;
			Assert::AreEqual(::Vector2::Magnitude(x, y), 0.f);
		}


		TEST_METHOD(SMagnitudeTest)
		{
			float x = 5;
			Assert::AreEqual(::Vector2::MagnitudeSquared(x), 25.f);
		}

		TEST_METHOD(DistanceTest)
		{
			Vector2 vec1 = Vector2(3.f, 4.f);
			Vector2 vec2 = Vector2(6.f, 8.f);
			Assert::AreEqual(::Vector2::Distance(vec1, vec2), 5.f);
		}

	};
}