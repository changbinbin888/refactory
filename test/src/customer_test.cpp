#include <gtest/gtest.h>
#include "mockcpp/mockcpp.h"
#include "mockcpp/mokc.h"
#include "customer_test.h"

#include "../../source/include/customer.h"
#include "../../source/include/movie.h"
#include "../../source/include/rental.h"

using namespace std;

class CustomerUT : public testing::Test
{
protected:
    void SetUp() override
    {
        cout << "--Gtest_Ut SetUP--" << endl;
    }

    void TearDown() override
    {
        cout << "--Gtest_Ut TearDown--" << endl;
    }
};

TEST_F(CustomerUT, ut_add_01)
{
    Customer zhangSan = Customer("ZhangSan");

    Movie movie1 = Movie("movie1", 2);
    Rental rental1 = Rental(movie1, 5);
    zhangSan.AddRental(rental1);

    Movie movie2 = Movie("movie2", 0);
    Rental rental2 = Rental(movie2, 3);
    zhangSan.AddRental(rental2);

    Movie movie3 = Movie("movie3", 1);
    Rental rental3 = Rental(movie3, 4);
    zhangSan.AddRental(rental3);  

    Movie movie4 = Movie("movie4", 5);
    Rental rental4 = Rental(movie4, 4);
    zhangSan.AddRental(rental4);  
    
    string ret = zhangSan.Statement();
    string expectRet = "Rental Record for ZhangSan\n\tmovie1\t4.500000\n\tmovie2\t3.500000\n\tmovie3\t12.000000\n\tmovie4\t0.000000\nAmount owed is 20.000000\nYou earned 5 frequent renter points";
    EXPECT_EQ(ret, expectRet);
}
