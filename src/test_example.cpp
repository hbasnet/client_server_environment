#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ExampleTestModule
#include <boost/test/unit_test.hpp>

// header defining all the code to be tested
#include "blackjack.h"

using namespace boost;
using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE(ExampleTestSuite)

struct TestFixtureSingleCard
{
     hand H;
     TestFixtureSingleCard()
     {
         card C;
         C.value = 10;
         C.suite = CLUBS;
         H.addCard (C);
     }

     ~TestFixtureSingleCard() 
     {
    
     }
};
 
BOOST_FIXTURE_TEST_CASE(lessthan21, TestFixtureSingleCard)
{
    // just contains 1 card
    BOOST_CHECK( ! H.is21 ());
   
    card CC;
    // add another one
    CC.value = 10;
    CC.suite = SPADES; 
    H.addCard (CC);
    BOOST_CHECK( ! H.is21 ());
    
}

BOOST_FIXTURE_TEST_CASE(over21, TestFixtureSingleCard)
{
    card CC;
    CC.value = 10;
    CC.suite = SPADES;
    H.addCard (CC);
    H.addCard (CC);
    BOOST_CHECK( ! H.is21 ());
}

BOOST_FIXTURE_TEST_CASE(equal21, TestFixtureSingleCard)
{
    card CC;
    CC.value = 11;
    CC.suite = SPADES;
    H.addCard (CC);
    BOOST_CHECK(  H.is21 ());
}

BOOST_AUTO_TEST_SUITE_END() 
