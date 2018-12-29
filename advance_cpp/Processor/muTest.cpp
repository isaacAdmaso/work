#include <iostream>
#include "mu_test.h"
#include "Idest.h"
#include "FileOut.h"
#include "Console.h"



UNIT(file)
using namespace std;
    FileOut fs("testFile");
    fs.PutString("in test");

END_UNIT


UNIT(screen)
using namespace std;
    Console fs(cout);
    fs.PutString("in test");

END_UNIT

TEST_SUITE(destination)
    TEST(file)
    TEST(screen)

END_SUITE


//int main(int argc, char *argv[])
//{
//    extern char *optarg;
//	extern int optind;
//    int op = -1;
//    const char 
//
//    while ((op = getopt(argc,argv, IN_FLAGS)) != -1)
//    {
//		switch (op) 
//        {
//        case 'p':
//            pause = 1;
//			break;
//        case 'd':
//            delete = 1;
//			break;
//        case 'v':
//            verb = 1;
//			break;
//        case 'r':
//            resume = 1;
//            break;
//        case '?':
//            fprintf(stderr,FLAG_ERR_STR);
//			return 1;
//		}
//    }
//
//    return 0;
//}
//