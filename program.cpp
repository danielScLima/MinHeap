// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "minheap.h"


bool checkEquality
(
	const std::vector<int> vec1,
	const std::vector<int> vec2
)
{
	if (vec1.size() != vec2.size())
		return false;
	
	for (int index = 0; index < vec1.size(); ++index)
	{
		if (vec1.at(index) != vec2.at(index))
			return false;
	}
	
	return true;
}

TEST_CASE( "Testing the insert call in the MINHEAP with each element", "[single-file]" )
{
	MinHeap minHeap;
	
	REQUIRE( minHeap.getNumberOfElementsInTheVector() == 0 );
	
	minHeap.insertInterface(40);
	
	REQUIRE( minHeap.getNumberOfElementsInTheVector() == 1 );
	
	minHeap.insertInterface(50);
	
	REQUIRE( minHeap.getNumberOfElementsInTheVector() == 2 );
	
	minHeap.insertInterface(35);
	
	REQUIRE( minHeap.getNumberOfElementsInTheVector() == 3 );
	
	minHeap.insertInterface(75);
	
	REQUIRE( minHeap.getNumberOfElementsInTheVector() == 4 );
	
	minHeap.insertInterface(20);
	
	REQUIRE( minHeap.getNumberOfElementsInTheVector() == 5 );
	
	minHeap.insertInterface(60);
	
	REQUIRE( minHeap.getNumberOfElementsInTheVector() == 6 );
	
	minHeap.insertInterface(4);
	
	REQUIRE( minHeap.getNumberOfElementsInTheVector() == 7 );
	
	minHeap.insertInterface(2);
	
	REQUIRE( minHeap.getNumberOfElementsInTheVector() == 8 );
}

TEST_CASE( "Testing the insert call in the MINHEAP", "[single-file]" )
{
	MinHeap minHeap;
	
	REQUIRE( minHeap.getNumberOfElementsInTheVector() == 0 );
	bool ret = checkEquality
	(
		minHeap.getHeapAsAVector(),
		{}
	);
	REQUIRE(ret);
	
	minHeap.insertInterface(40);
	REQUIRE( minHeap.getNumberOfElementsInTheVector() == 1 );
	ret = checkEquality
	(
		minHeap.getHeapAsAVector(),
		{40}
	);
	REQUIRE(ret);
	
	
	minHeap.insertInterface(50);
	REQUIRE( minHeap.getNumberOfElementsInTheVector() == 2 );
	ret = checkEquality
	(
		minHeap.getHeapAsAVector(),
		{40,50}
	);
	REQUIRE(ret);
	
	minHeap.insertInterface(75);
	REQUIRE( minHeap.getNumberOfElementsInTheVector() == 3 );
	ret = checkEquality
	(
		minHeap.getHeapAsAVector(),
		{40,50,75}
	);
	REQUIRE(ret);
	
	minHeap.insertInterface(35);
	REQUIRE( minHeap.getNumberOfElementsInTheVector() == 4 );
	ret = checkEquality
	(
		minHeap.getHeapAsAVector(),
		{35,40,75,50}
	);
	REQUIRE(ret);
	
	minHeap.insertInterface(20);
	REQUIRE( minHeap.getNumberOfElementsInTheVector() == 5 );
	ret = checkEquality
	(
		minHeap.getHeapAsAVector(),
		{20,35,75,50,40}
	);
	REQUIRE(ret);

	minHeap.insertInterface(60);	
	REQUIRE( minHeap.getNumberOfElementsInTheVector() == 6 );
	ret = checkEquality
	(
		minHeap.getHeapAsAVector(),
		{20,35,60,50,40,75}
	);
	REQUIRE(ret);
	
	minHeap.insertInterface(4);
	REQUIRE( minHeap.getNumberOfElementsInTheVector() == 7 );
	ret = checkEquality
	(
		minHeap.getHeapAsAVector(),
		{4,35,20,50,40,75,60}
	);
	REQUIRE(ret);
	
	minHeap.insertInterface(2);
	REQUIRE( minHeap.getNumberOfElementsInTheVector() == 8 );
	ret = checkEquality
	(
		minHeap.getHeapAsAVector(),
		{2,4,20,35,40,75,60,50}
	);
	REQUIRE(ret);
}

TEST_CASE( "Testing the remove min call in the MINHEAP", "[single-file]" )
{
	MinHeap minHeap;
	minHeap.insertInterface(40);
	minHeap.insertInterface(50);
	minHeap.insertInterface(75);
	minHeap.insertInterface(35);
	minHeap.insertInterface(20);
	minHeap.insertInterface(60);
	minHeap.insertInterface(4);
	minHeap.insertInterface(2);
	
	bool ret = checkEquality
	(
		minHeap.getHeapAsAVector(),
		{2,4,20,35,40,75,60,50}
	);
	REQUIRE(ret);
	
	minHeap.removeTheSmallerNumber();
	ret = checkEquality
	(
		minHeap.getHeapAsAVector(),
		{4,35,20,50,40,75,60}
	);
	REQUIRE(ret);
	
	minHeap.removeTheSmallerNumber();
	ret = checkEquality
	(
		minHeap.getHeapAsAVector(),
		{20,35,60,50,40,75}
	);
	REQUIRE(ret);
	
	minHeap.removeTheSmallerNumber();
	ret = checkEquality
	(
		minHeap.getHeapAsAVector(),
		{35,40,60,50,75}
	);
	REQUIRE(ret);
	
	minHeap.removeTheSmallerNumber();
	ret = checkEquality
	(
		minHeap.getHeapAsAVector(),
		{40,50,60,75}
	);
	REQUIRE(ret);
	
	minHeap.removeTheSmallerNumber();
	ret = checkEquality
	(
		minHeap.getHeapAsAVector(),
		{50,75,60}
	);
	REQUIRE(ret);
	
	minHeap.removeTheSmallerNumber();
	ret = checkEquality
	(
		minHeap.getHeapAsAVector(),
		{60,75}
	);
	REQUIRE(ret);
	
	minHeap.removeTheSmallerNumber();
	ret = checkEquality
	(
		minHeap.getHeapAsAVector(),
		{75}
	);
	REQUIRE(ret);
	
	minHeap.removeTheSmallerNumber();
	ret = checkEquality
	(
		minHeap.getHeapAsAVector(),
		{}
	);
	REQUIRE(ret);

}


