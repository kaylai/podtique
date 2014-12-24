//
//  BandPassFilter.cpp
//  Podtique
//
//  Created by Roderick Mann on 12/18/14.
//  Copyright (c) 2014 Latency: Zero. All rights reserved.
//

#include "BandPassFilter.h"









#ifndef SAMPLEFILTER_H_
#define SAMPLEFILTER_H_

/*

FIR filter designed with
 http://t-filter.appspot.com

sampling frequency: 44100 Hz

* 0 Hz - 500 Hz
  gain = 0
  desired attenuation = -40 dB
  actual attenuation = -40.12248042438191 dB

* 600 Hz - 2000 Hz
  gain = 1
  desired ripple = 5 dB
  actual ripple = 4.11525619722424 dB

* 2200 Hz - 22050 Hz
  gain = 0
  desired attenuation = -40 dB
  actual attenuation = -40.12248042438191 dB

*/

#define SAMPLEFILTER_TAP_NUM 441

typedef struct {
  double history[SAMPLEFILTER_TAP_NUM];
  unsigned int last_index;
} SampleFilter;

void SampleFilter_init(SampleFilter* f);
void SampleFilter_put(SampleFilter* f, double input);
double SampleFilter_get(SampleFilter* f);

#endif




static double filter_taps[SAMPLEFILTER_TAP_NUM] = {
  -0.006274280829914131,
  -0.0029406080766914275,
  -0.003435879548297929,
  -0.0038315300028186504,
  -0.004085335205125379,
  -0.004159303336206203,
  -0.004022511560903022,
  -0.0036541866590978837,
  -0.0030461996998527034,
  -0.0022043412195585192,
  -0.0011498867601987405,
  0.0000809486624196081,
  0.0014388638008383727,
  0.002862339874797234,
  0.0042823709598145375,
  0.005625246488185198,
  0.0068178456442493495,
  0.007791721114743991,
  0.008487977747267707,
  0.008861447507145558,
  0.008884179398880592,
  0.008547372406477403,
  0.007862703704240444,
  0.00686215942754312,
  0.00559623264524672,
  0.004131223655793265,
  0.002544894765341579,
  0.0009218641906669752,
  -0.0006520909862579974,
  -0.0020957299742960732,
  -0.003337566073678685,
  -0.00432041082153631,
  -0.005005195651704975,
  -0.005373469592415084,
  -0.005428368370306704,
  -0.005193972482076302,
  -0.004712946700870186,
  -0.004043400046691386,
  -0.0032541783723062908,
  -0.0024196210024281296,
  -0.001613911926828103,
  -0.0009052513716415131,
  -0.0003508966192985476,
  0.000007001271726107396,
  0.00014420704061921975,
  0.00005620139558071044,
  -0.00024188302834393487,
  -0.0007163955697157449,
  -0.0013191267558788982,
  -0.0019907744727389338,
  -0.002666068486579132,
  -0.003279136217068095,
  -0.0037691228619061022,
  -0.004085727583024575,
  -0.004192616411826713,
  -0.004070540848227946,
  -0.0037188572194451998,
  -0.003157105935337111,
  -0.002419294979198483,
  -0.0015572529851203365,
  -0.0006283802504702432,
  0.0003005507142904238,
  0.0011655191962782667,
  0.001909244368645312,
  0.0024822706443141853,
  0.002850960549334585,
  0.0030004969197693398,
  0.0029324730779521895,
  0.00266712674206838,
  0.0022427496330016273,
  0.0017090962661805232,
  0.0011266456829543514,
  0.0005573494558747953,
  0.00006364533343611275,
  -0.00029982944758449507,
  -0.0004905132915529633,
  -0.00048178434290894654,
  -0.0002646085055189836,
  0.00015114129930750481,
  0.0007372983682973066,
  0.001449454713529127,
  0.002231034708650902,
  0.0030184535205966274,
  0.003745773487010739,
  0.0043506879962649575,
  0.004779483993170759,
  0.004992098432383054,
  0.004965694149372408,
  0.004696849550531359,
  0.004201900996361163,
  0.003515786131178279,
  0.002689185065539743,
  0.0017845294320846018,
  0.0008707210614636998,
  0.000016833274018207193,
  -0.0007136901687750846,
  -0.0012685625478606089,
  -0.0016109411513450726,
  -0.0017226148694895844,
  -0.0016057831667214359,
  -0.0012829655307751108,
  -0.0007954557168030659,
  -0.00020017637730361572,
  0.0004350749273635335,
  0.0010378309035727546,
  0.0015372220921004126,
  0.0018707041679487146,
  0.0019893413039167424,
  0.0018624493245755253,
  0.001480257786518591,
  0.0008546050651656989,
  0.000018726083402645613,
  -0.000974796250257063,
  -0.0020574723736581984,
  -0.0031507423741497635,
  -0.004172643160702683,
  -0.005046715954705054,
  -0.005707246025804075,
  -0.0061059508789781365,
  -0.0062125717290089835,
  -0.006018636253360813,
  -0.005541454651275906,
  -0.004825083772723144,
  -0.003934963834760546,
  -0.002945107112996019,
  -0.0019333126617626696,
  -0.00099117381506088,
  -0.00021083077173102418,
  0.00036635892279394424,
  0.0006684992993482194,
  0.0006853878668831661,
  0.0004138529872841556,
  -0.00011592569366685257,
  -0.0008507086149337635,
  -0.0017166854416145153,
  -0.002625530102764429,
  -0.003481587883188211,
  -0.004190714669134884,
  -0.004667826603903052,
  -0.004844270601183454,
  -0.004675180710644256,
  -0.004142946653143715,
  -0.003260420631635672,
  -0.0020697250402178383,
  -0.0006401570930025494,
  0.0009371782172737172,
  0.002556554236971728,
  0.004106322280598087,
  0.005477815984931488,
  0.006574792217878414,
  0.007321892112969939,
  0.007671431988785316,
  0.007608105147389888,
  0.0071506306018694595,
  0.00635134598597078,
  0.005292406902589793,
  0.004079347835678206,
  0.0028324931090909725,
  0.0016769459468533785,
  0.0007319321762049903,
  0.00010035260107974504,
  -0.00014072488019248563,
  0.00005230162264504238,
  0.0006847906910298935,
  0.001721782823264158,
  0.0030898780145788398,
  0.004681893318933537,
  0.006364530942064177,
  0.007988813701570018,
  0.009402105473817313,
  0.010461132770594211,
  0.011044155212574307,
  0.011062022107381537,
  0.010466862161382696,
  0.009258449786330458,
  0.007485152908349726,
  0.005242589300516825,
  0.0026669921988595816,
  -0.00007389158160261682,
  -0.0027935277984242465,
  -0.005301973929560854,
  -0.007420814389579573,
  -0.00899865508306011,
  -0.009924911643814404,
  -0.010142733345217746,
  -0.009650917844282165,
  -0.008517730862900717,
  -0.006860861230271504,
  -0.004862887944788956,
  -0.0027402618459952074,
  -0.0007349313053308252,
  0.0008993473083235211,
  0.0019243994703064227,
  0.002137539713217065,
  0.0013857066202030762,
  -0.0004165914519891885,
  -0.0032738412243642303,
  -0.0071044206783527925,
  -0.01173979947990524,
  -0.01693394357156065,
  -0.022371444553961718,
  -0.027687067804244927,
  -0.03248781901726403,
  -0.03637956617487544,
  -0.03899337316013189,
  -0.040011587188765976,
  -0.0391916492438006,
  -0.036386931731920306,
  -0.031561603423424026,
  -0.024798505297065482,
  -0.016299734815618153,
  -0.006378546411443907,
  0.004554981843175956,
  0.016015241556994953,
  0.02746733037844825,
  0.038357472931058255,
  0.04814535942566941,
  0.05633621023640735,
  0.06251021674899225,
  0.06634798189577662,
  0.06764989110848911,
  0.06634798189577662,
  0.06251021674899225,
  0.05633621023640735,
  0.04814535942566941,
  0.038357472931058255,
  0.02746733037844825,
  0.016015241556994953,
  0.004554981843175956,
  -0.006378546411443907,
  -0.016299734815618153,
  -0.024798505297065482,
  -0.031561603423424026,
  -0.036386931731920306,
  -0.0391916492438006,
  -0.040011587188765976,
  -0.03899337316013189,
  -0.03637956617487544,
  -0.03248781901726403,
  -0.027687067804244927,
  -0.022371444553961718,
  -0.01693394357156065,
  -0.01173979947990524,
  -0.0071044206783527925,
  -0.0032738412243642303,
  -0.0004165914519891885,
  0.0013857066202030762,
  0.002137539713217065,
  0.0019243994703064227,
  0.0008993473083235211,
  -0.0007349313053308252,
  -0.0027402618459952074,
  -0.004862887944788956,
  -0.006860861230271504,
  -0.008517730862900717,
  -0.009650917844282165,
  -0.010142733345217746,
  -0.009924911643814404,
  -0.00899865508306011,
  -0.007420814389579573,
  -0.005301973929560854,
  -0.0027935277984242465,
  -0.00007389158160261682,
  0.0026669921988595816,
  0.005242589300516825,
  0.007485152908349726,
  0.009258449786330458,
  0.010466862161382696,
  0.011062022107381537,
  0.011044155212574307,
  0.010461132770594211,
  0.009402105473817313,
  0.007988813701570018,
  0.006364530942064177,
  0.004681893318933537,
  0.0030898780145788398,
  0.001721782823264158,
  0.0006847906910298935,
  0.00005230162264504238,
  -0.00014072488019248563,
  0.00010035260107974504,
  0.0007319321762049903,
  0.0016769459468533785,
  0.0028324931090909725,
  0.004079347835678206,
  0.005292406902589793,
  0.00635134598597078,
  0.0071506306018694595,
  0.007608105147389888,
  0.007671431988785316,
  0.007321892112969939,
  0.006574792217878414,
  0.005477815984931488,
  0.004106322280598087,
  0.002556554236971728,
  0.0009371782172737172,
  -0.0006401570930025494,
  -0.0020697250402178383,
  -0.003260420631635672,
  -0.004142946653143715,
  -0.004675180710644256,
  -0.004844270601183454,
  -0.004667826603903052,
  -0.004190714669134884,
  -0.003481587883188211,
  -0.002625530102764429,
  -0.0017166854416145153,
  -0.0008507086149337635,
  -0.00011592569366685257,
  0.0004138529872841556,
  0.0006853878668831661,
  0.0006684992993482194,
  0.00036635892279394424,
  -0.00021083077173102418,
  -0.00099117381506088,
  -0.0019333126617626696,
  -0.002945107112996019,
  -0.003934963834760546,
  -0.004825083772723144,
  -0.005541454651275906,
  -0.006018636253360813,
  -0.0062125717290089835,
  -0.0061059508789781365,
  -0.005707246025804075,
  -0.005046715954705054,
  -0.004172643160702683,
  -0.0031507423741497635,
  -0.0020574723736581984,
  -0.000974796250257063,
  0.000018726083402645613,
  0.0008546050651656989,
  0.001480257786518591,
  0.0018624493245755253,
  0.0019893413039167424,
  0.0018707041679487146,
  0.0015372220921004126,
  0.0010378309035727546,
  0.0004350749273635335,
  -0.00020017637730361572,
  -0.0007954557168030659,
  -0.0012829655307751108,
  -0.0016057831667214359,
  -0.0017226148694895844,
  -0.0016109411513450726,
  -0.0012685625478606089,
  -0.0007136901687750846,
  0.000016833274018207193,
  0.0008707210614636998,
  0.0017845294320846018,
  0.002689185065539743,
  0.003515786131178279,
  0.004201900996361163,
  0.004696849550531359,
  0.004965694149372408,
  0.004992098432383054,
  0.004779483993170759,
  0.0043506879962649575,
  0.003745773487010739,
  0.0030184535205966274,
  0.002231034708650902,
  0.001449454713529127,
  0.0007372983682973066,
  0.00015114129930750481,
  -0.0002646085055189836,
  -0.00048178434290894654,
  -0.0004905132915529633,
  -0.00029982944758449507,
  0.00006364533343611275,
  0.0005573494558747953,
  0.0011266456829543514,
  0.0017090962661805232,
  0.0022427496330016273,
  0.00266712674206838,
  0.0029324730779521895,
  0.0030004969197693398,
  0.002850960549334585,
  0.0024822706443141853,
  0.001909244368645312,
  0.0011655191962782667,
  0.0003005507142904238,
  -0.0006283802504702432,
  -0.0015572529851203365,
  -0.002419294979198483,
  -0.003157105935337111,
  -0.0037188572194451998,
  -0.004070540848227946,
  -0.004192616411826713,
  -0.004085727583024575,
  -0.0037691228619061022,
  -0.003279136217068095,
  -0.002666068486579132,
  -0.0019907744727389338,
  -0.0013191267558788982,
  -0.0007163955697157449,
  -0.00024188302834393487,
  0.00005620139558071044,
  0.00014420704061921975,
  0.000007001271726107396,
  -0.0003508966192985476,
  -0.0009052513716415131,
  -0.001613911926828103,
  -0.0024196210024281296,
  -0.0032541783723062908,
  -0.004043400046691386,
  -0.004712946700870186,
  -0.005193972482076302,
  -0.005428368370306704,
  -0.005373469592415084,
  -0.005005195651704975,
  -0.00432041082153631,
  -0.003337566073678685,
  -0.0020957299742960732,
  -0.0006520909862579974,
  0.0009218641906669752,
  0.002544894765341579,
  0.004131223655793265,
  0.00559623264524672,
  0.00686215942754312,
  0.007862703704240444,
  0.008547372406477403,
  0.008884179398880592,
  0.008861447507145558,
  0.008487977747267707,
  0.007791721114743991,
  0.0068178456442493495,
  0.005625246488185198,
  0.0042823709598145375,
  0.002862339874797234,
  0.0014388638008383727,
  0.0000809486624196081,
  -0.0011498867601987405,
  -0.0022043412195585192,
  -0.0030461996998527034,
  -0.0036541866590978837,
  -0.004022511560903022,
  -0.004159303336206203,
  -0.004085335205125379,
  -0.0038315300028186504,
  -0.003435879548297929,
  -0.0029406080766914275,
  -0.006274280829914131
};

void SampleFilter_init(SampleFilter* f) {
  int i;
  for(i = 0; i < SAMPLEFILTER_TAP_NUM; ++i)
    f->history[i] = 0;
  f->last_index = 0;
}

void SampleFilter_put(SampleFilter* f, double input) {
  f->history[f->last_index++] = input;
  if(f->last_index == SAMPLEFILTER_TAP_NUM)
    f->last_index = 0;
}

double SampleFilter_get(SampleFilter* f) {
  double acc = 0;
  int index = f->last_index, i;
  for(i = 0; i < SAMPLEFILTER_TAP_NUM; ++i) {
    index = index != 0 ? index-1 : SAMPLEFILTER_TAP_NUM-1;
    acc += f->history[index] * filter_taps[i];
  };
  return acc;
}