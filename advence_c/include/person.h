#ifndef __PERS_H_
#define __PERS_H_
#include<stdlib.h>
#include <stdio.h>
 
typedef struct
{
	size_t id;
	int random;
	char animal[32];
} Person;

int cmp(Person* _a,Person* _b)
{
    return _a->random > _b->random;
}

void Person_print(Person *_p)
{
	printf("\n %ld, %d , %s\n",_p->id,_p->random,_p->animal);
}

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

#endif /*__PERS_H_*/
