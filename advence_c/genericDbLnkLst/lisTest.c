#include <stdio.h>
#include "list_functions.h"
#include "mu_test.h"
#include <string.h>

#define SIZE_ARR(A) sizeof(A)/sizeof(A[0]) 



Person people[] = {

	{1, 708465, "Manatee"},

	{2, 804738, "Cormorant, flightless"},

	{3, 432634, "Giant anteater"},

	{4, -191979, "Least chipmunk"},

	{5, 740434, "Owl, great horned"},

	{6, -598520, "Ibis, sacred"},

	{7, -777850, "Black-backed magpie"},

	{8, 296847, "Cobra, egyptian"},

	{9, -264536, "Black spider monkey"},

	{10, -607105, "Russian dragonfly"},

	{11, -267104, "Antelope, four-horned"},

	{12, 337636, "Asian water buffalo"},

	{13, 471153, "Flamingo, roseat"},

	{14, -977605, "Gulls (unidentified)"},

	{15, 792008, "Mandras tree shrew"},

	{16, 57581, "Puma"},

	{17, 308928, "Olive baboon"},

	{18, -28487, "Galapagos penguin"},

	{19, 730596, "Vulture, white-rumped"},

	{20, -459822, "Raven, white-necked"},

	{21, -535244, "Brolga crane"},

	{22, 221091, "Hornbill, leadbeateri's ground"},

	{23, -133805, "Rufous-collared sparrow"},

	{24, 446085, "Moose"},

	{25, -143827, "Duiker, gray"},

	{26, -457153, "Pine siskin"},

	{27, -132202, "Bat-eared fox"},

	{28, -483433, "Toucan, red-billed"},

	{29, 694444, "Macaque, bonnet"},

	{30, -857195, "Capuchin, white-fronted"},

	{31, 117910, "White stork"},

	{32, 337044, "Great egret"},

	{33, -639826, "Pigeon, wood"},

	{34, 592079, "Steller's sea lion"},

	{35, -218136, "Possum, ring-tailed"},

	{36, 345462, "Dragon, netted rock"},

	{37, 841723, "Scottish highland cow"},

	{38, -55541, "Lion, galapagos sea"},

	{39, 108364, "Gull, swallow-tail"},

	{40, 115977, "Asian red fox"},

	{41, 775768, "Dragonfly, russian"},

	{42, -870178, "American buffalo"},

	{43, -858156, "Ostrich"},

	{44, 551962, "Koala"},

	{45, -278112, "Hottentot teal"},

	{46, 499550, "Waxbill, violet-eared"},

	{47, -806642, "White stork"},

	{48, 961912, "Eastern fox squirrel"},

	{49, -921007, "Hornbill, leadbeateri's ground"},

	{50, 409572, "Crane, sarus"},

	{51, -39219, "Beaver, european"},

	{52, 562224, "Red squirrel"},

	{53, 155810, "Seal, southern elephant"},

	{54, -739806, "Springbuck"},

	{55, -908511, "Duck, blue"},

	{56, 834987, "Monitor lizard (unidentified)"},

	{57, -71541, "Marmot, hoary"},

	{58, 606222, "Deer, black-tailed"},

	{59, 240656, "Crimson-breasted shrike"},

	{60, -904073, "Gazelle, grant's"},

	{61, -299171, "Langur, common"},

	{62, 197850, "Komodo dragon"},

	{63, 944875, "Bateleur eagle"},

	{64, -837564, "Rufous-collared sparrow"},

	{65, 53287, "Tropical buckeye butterfly"},

	{66, 238830, "Vervet monkey"},

	{67, 151803, "Pied butcher bird"},

	{68, -653859, "Turtle, snake-necked"},

	{69, 280489, "Rufous-collared sparrow"},

	{70, -701158, "Wolf spider"},

	{71, -42572, "Tree porcupine"},

	{72, -601588, "Lizard, giant girdled"},

	{73, -441553, "Hornbill, red-billed"},

	{74, -332443, "Crested screamer"},

	{75, -327611, "Black-crowned crane"},

	{76, -322173, "Greater sage grouse"},

	{77, 243735, "Eagle, long-crested hawk"},

	{78, 11833, "Phalarope, northern"},

	{79, -368549, "Magistrate black colobus"},

	{80, -423225, "Shark, blue"},

	{81, 764415, "Mexican boa"},

	{82, -577707, "Long-nosed bandicoot"},

	{83, 584136, "Javanese cormorant"},

	{84, -174144, "Flicker, field"},

	{85, 633159, "Snake, buttermilk"},

	{86, 250190, "Seal, southern elephant"},

	{87, -271336, "Genet, small-spotted"},

	{88, 877347, "White stork"},

	{89, -322618, "Anaconda (unidentified)"},

	{90, -124956, "Wild water buffalo"},

	{91, -982007, "Cape wild cat"},

	{92, -384876, "Sloth, two-toed tree"},

	{93, -367503, "Herring gull"},

	{94, -518159, "Southern tamandua"},

	{95, 992219, "Boa, cook's tree"},

	{96, -57383, "Common melba finch"},

	{97, 426018, "Giant anteater"},

	{98, 718107, "Zorro, common"},

	{99, 828803, "Leopard, indian"},

	{100, -301330, "Kingfisher, white-throated"}

};







UNIT (list_create)
	List* list = List_Create();
	ASSERT_THAT(list != NULL);
END_UNIT	 


UNIT (List_Push_Head_NULL)
	int num;

	num = 4;
	ASSERT_THAT(List_PushHead(NULL,&num) == LIST_UNINITIALIZED_ERROR);
END_UNIT


UNIT (List_Push_Head_Normal)
	int num;
	List* list;

	list = List_Create();
	ASSERT_THAT(List_PushHead(list,&num) == LIST_SUCCESS);
END_UNIT



UNIT (List_Push_Head_After_Destroyed)
	int num,num1;
	List* list = List_Create();
	num = 5;
	num1 = 5;
	List_PushHead(list,&num);
	ASSERT_THAT(List_PushHead(list,&num1) == LIST_SUCCESS);          
END_UNIT	 


UNIT (List_Push_Tail_NULL)
	int num = 3;
	ASSERT_THAT(List_PushTail(NULL,&num) == LIST_UNINITIALIZED_ERROR);
END_UNIT



UNIT (List_Push_Tail_Nurmal)
	int num,num1;
	List* list = List_Create();
	num = 5;
	num1 = 5;
	ASSERT_THAT(List_PushTail(list,&num) == LIST_SUCCESS);
	ASSERT_THAT(List_PushTail(list,&num1) == LIST_SUCCESS);
END_UNIT


/*
UNIT (List_Push_Tail_After_Destroyed)
	int num,num1;
	List* list = List_Create();
	num = 5;
	num1 = 5;
	List_PushTail(list,&num);
	ASSERT_THAT(List_PushTail(list,&num1) == LIST_SUCCESS);
END_UNIT
*/

UNIT (List_Pop_Head_NULL_Data)
	int i,*arr1 ,*arr0,arr[] = {13,2,3,4,1,2,34,12,567,234};
	List* list = List_Create();

	
	arr1 = &arr[1];
	arr0 = &arr[0];
	ASSERT_THAT(List_PopHead(list,NULL) == LIST_UNINITIALIZED_ERROR);
	ASSERT_THAT(List_PushTail(list,arr) == LIST_SUCCESS);
	ASSERT_THAT(List_PushHead(list,arr+1) ==  LIST_SUCCESS);
	ASSERT_THAT(List_PopHead(list,(void**)&arr0) == LIST_SUCCESS);
	ASSERT_THAT(List_PopTail(list,(void**)&arr1) == LIST_SUCCESS);
	printf("\n%d %d\n",*arr0,*arr1);
	printf("\n%d %d\n",arr[0],arr[1]);
	ASSERT_THAT(List_Size(list) == 0 );
	for(i = 0;i < SIZE_ARR(arr);++i)
		ASSERT_THAT(List_PushTail(list,arr+i) == LIST_SUCCESS);


END_UNIT



UNIT (List_Size_check)
	int num,num1,*ptr1,*ptr;
	List* list = NULL;
	
	num = 3;
	num1 = 4;
	ptr = &num;
	ptr1 = &num1;
	ASSERT_THAT(List_PushTail(list,ptr1) == LIST_UNINITIALIZED_ERROR);
	ASSERT_THAT(List_Size(list) == 0);
	list = List_Create();
	ASSERT_THAT(List_PushHead(list,ptr)  == LIST_SUCCESS);
	List_PushTail(list,ptr1);
	List_PushTail(list,ptr);
	ASSERT_THAT(List_Size(list) == 3);
	List_Print(list);


END_UNIT

UNIT (List_W_string)
	int i;
	char* item;
	char* str[] = {"yitshak","admaaso","i am","late","shoshi"};
	List* list = NULL;
	ListItr Lidx = NULL;

	ASSERT_THAT((list = List_Create()) != NULL);

	ASSERT_THAT(List_PushHead(list,NULL) == LIST_UNINITIALIZED_ERROR);
	ASSERT_THAT(List_PushTail(list,NULL) == LIST_UNINITIALIZED_ERROR);
	for(i = 0;i < SIZE_ARR(str);++i)
	{
		ASSERT_THAT(List_PushTail(list,str[i]) == LIST_SUCCESS);
		List_Prstr(list);

	}
	ASSERT_THAT(List_Size(list) == SIZE_ARR(str));
	ASSERT_THAT(List_PopHead(list,(void**)&item) == LIST_SUCCESS);
	printf("\n%s , %s\n",item,str[0]);
	ASSERT_THAT(List_PopTail(list,(void**)&item) == LIST_SUCCESS);
	printf("\n%s , %s\n",item,str[SIZE_ARR(str)-1]);
	ASSERT_THAT(item == str[SIZE_ARR(str)-1]);
	ASSERT_THAT(List_Size(list) == SIZE_ARR(str) - 2);
	List_Prstr(list);
	Lidx = ListItr_Begin(list);
	printf("\n%s\n",item);
	ASSERT_THAT(item = ListItr_Set(Lidx,item));
	List_Prstr(list);
	printf("\n%s\n",item);
	
	
END_UNIT



UNIT (List_W_struct)

	Person  p = {666,101,"lion"};
	Person *_p = &p;
	int i;
	List* list = NULL;
	ListItr start = NULL,end = NULL;

	ASSERT_THAT((list = List_Create()) != NULL);
	ASSERT_THAT(List_PushTail(list,NULL) == LIST_UNINITIALIZED_ERROR);
	for(i = 0;i < SIZE_ARR(people);++i)
		ASSERT_THAT(List_PushTail(list,people+i) == LIST_SUCCESS);
	ASSERT_THAT(List_PushTail(list,&p) == LIST_SUCCESS);
	ASSERT_THAT(List_Size(list) == SIZE_ARR(people) + 1);
	ASSERT_THAT(List_PopHead(list,(void**)(&_p)) == LIST_SUCCESS);
	ASSERT_THAT(List_PopTail(list,(void**)(&_p)) == LIST_SUCCESS);
	ASSERT_THAT(List_PopTail(list,(void**)(&_p)) == LIST_SUCCESS);
	ASSERT_THAT(List_Size(list) == SIZE_ARR(people)-2);
	List_Prpep(list);
	start = ListItr_Begin(list);
	end  = ListItr_End(list);
	ListItr_Sort(start,end,Person_cmp);
	List_Prpep(list);
	for(i = 2;i < SIZE_ARR(people);++i)
		ASSERT_THAT(List_PopHead(list,(void**)(&_p)) == LIST_SUCCESS);


END_UNIT

TEST_SUITE(list tester)
	TEST(list_create)
	TEST(List_Push_Head_NULL)
	TEST(List_Push_Head_Normal)
	TEST(List_Push_Head_After_Destroyed)
	TEST(List_Push_Tail_NULL)
	TEST(List_Push_Tail_Nurmal)
	TEST(List_Pop_Head_NULL_Data)
	TEST (List_Size_check)
	TEST(List_W_string) 
	TEST(List_W_struct)
	
END_SUITE	












