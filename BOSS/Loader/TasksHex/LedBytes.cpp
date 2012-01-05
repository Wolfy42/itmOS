
#include "LedBytes.h"

LedBytes::LedBytes() {}

CodeBytes* LedBytes::getCodeBytes()  {

	CodeBytes* cb = new CodeBytes();

	cb->byte0 = ":020000040002F8:20000000000029F09001828C01087C010400900400FBF0110403070403040404FB040301EA:200080000101FB0304020400EA1EFF08041401000000047CFF08000000042C8000000500F2:20010000642800071600080C040000000700021F048C01007A0C0800002408C40C040000D7:20018000000428580000060068240400014C000C0C04000000070002EC048C0100510C08F1:2002000000000C08B40F0C080400001401055C034254033F08044708040143080402340CAD:2002800000110804032D08040434080408250000001820040000001825000F0E08040000F2:20030000000424F800009C007C20044CA000CC0114044CA01F00001800081C5F002C0000DE:200380002404001C0800140C000C107000000000F80400F00800E80C00E0106000D4000059:20040000CC0400C40800BC0C00B4105000A80000A00400980800900C00881040007C000088:200480007404006C0800640C005C103000500000480400400800380C003010200014019B2C:2005000001A901B701C501D301E11100E80800341200D408002E0C00BC081028060407EAA9:200580008EEE01F2000E0C0400000004048C01005E0C040000180110000800041E04000074:20060000180110000C00041E0800000400185A080C000004001C0006001000185704050043:200680000400185004040C0010D4343C949038343C949038343C949038343C949038343C56:20070000949038343C94903814A80C040000000428EA00000600A424040000DE000C0C0403:200780000000000700027E048C0100E30C08000096080800007B0808000081080800008FF9:2008000008F40C040000000424B200002200E42004000000040004040400080804000C0C8C:2008800004001010040014140400181804001C1C000C0C040000000428820000050028247D:200900000400BE000C0E0804000C0400E40E000428DF090400DB050800EF01F1F50E080001:20098000000004545700000900805000955B0096285700080C040000000B0002285F00021C:200A00005C048C0100490C0400041E00300400040008B1085C080245300000300400040062:200A800008A2085208023630000030040004000893083908022730000034040004000884A5:200B0000083902300817303400D4F4E4080000000404E9000002007C0000080C04000000A4:200B800004048C0100E90C0038040008470866343400FC08025038003C00180400042D084B:200C000008000C08040D1A000C0C8E1F000C0C7A1A000C0C9315040810000C0C9A1400106A:200C80009D090D00EB01E401DD01EAFF1800080000000460870000070061006008000C1D05:200D000000080C040000000B00020C2700005D048C01007B0C540800000004105F00000433:200D800000100C006800080C0400000007000275048C01005A0C0800000002013F000008F0:200E00000C0400000002013400000C0E080400043E0E0C04000400BC0C0C040004D40C0C39:200E80000400000002011500000C0E0804000408AB0E0C040004B70C0C040000000201FC65:200F000000000C040000041E04000004041E0C000000040CE700000B049B0000C0003E00CA:200F800004000008000C0C0400000006004B048C0100DC0C0E000004C900080004C40004B0:20100000000004C30004000000080C08B5000408008600080174040800080400ED0E0E0004:2010800000016E040008049A000004017C08010804950000040172FF040E080000B50004C3:20110000810000016C00047F000001650000040139000004080C0400008C0C600C0F040087:20118000000C0C04CD00080404080000FF000F0400041E0400041E0C0400000004013D00A2:201200000002000419000C0E0400000004022D0000090408EA0000DE0004011B000E0E0441:201280000000000403160000090408D30000D7000402CC000E080000000410000000040072:201300009400900C00080C0400000007000097048C0100FB0C040028041E04002C041E04AB:2013800000041E53616563D4AC1C00180400043C0801140914080C0C1401001401140426F5:20140000140CF008001006041D0C010017041000F501FF18000800F4000008E800E400D593:20148000D00100FF080014080400B00C0010100400100CEA00FB0C08F21001100801080437:201500001000EE14000014080400300C00101004000F0CBD00FB10080C0CD9100110041028:2015800000EF10140008000000040C50000006002A009408009E00080C0400000007000047:201600002B048C0100490C0E0DDA0D5A020DE80E001C2118C000483C006C4C5C08000000A3:20168000040C19000004001B00440800080C0400000007000024048C0100140C8406A2088E:201700000400081E08000000040CF100000A00B40800AC00000043000400080C04000000C5:2017800004048C0100E90C0E000004C908000810040400F00008043C0008000155EA9C00A0:201800000400041E1E08000000040CB000000400B200700800080C04000000070000BB04B0:201880008C0100AB0C04002000041E080400081EFC000E0D050D2E020D110E0800000004FB:201900000C7A000004007C00F40800080C0400000007000085048C0100750C0400A4000463:201980001E080400081E0C000098000404680C0604010450040CF801890004042C0CE804BA:201A0000010414040CF8E01C00803000B2000C040004080003040087B20100240484EF301F:201A8000010014040E011C2014001E0C001E1E8C8800600D780D2F020D87600000F0003815:201B0000300105FB0000F000063404F500F0A834001E1A1E080400000400011200081E08FE:201B80000400000400011200081E080400000400011200081E080400000400011200000197:201C0000081E0C0804000C1E0F0C0804000000040CAA000008000400000804000C0800004F:201C80000F04000000041E04000004041E04000008041E011E0800000400540254040106D7:201D0000005801040401F8081E0400000720041E080000E000F20808040000040C081E08CA:201D8000000080F208080000BFEC0808000000E6080804000004FF0000044C04081E080483:201E000000000420081E08B40000B40C000C00B40C000C081E08B40009000C040C08000C09:201E8000040C03B400F2F6081E080400FF000C080CFF081E0014040004080707000C800C53:201F0000000C400C00BCBE00BECA0010DB1400080400000408081E040000081008041E04E0:201F80000000104010041E0400000004041E040000101010041E001C18080400080C0707DD:20200000004D00600C00690018C4000CA600046D1C000800001401040400000001081E082F:2020800000001420040400000001081E08040004000000081E08040000040000081E3074CD:2021000000003068000000040005000308023C01083C0000EE30241C000C0000001EA490D4:202180009CF8AC0E0000B40E0808B4C6000402040B00000004000E0014040000000C030057:202200000C2B0C00040C3700F50C04000C0C04040C001A101000001000040C089500080301:20228000000808870C01000C04040C0814000804000404040C08081E0804000408081E0CC2:202300000804000800000A0804000408040400010100000C1E00140400000C0C000C5300C4:202380000804080C040500001010140000140804000000040CC600001E00040000080400BC:2024000000082F000C05000C08210C000010100000100004004C0008001400040000080487:202480001E0400000004080C041E001C0C08040008000C421408140C0CE5000C3918180CA8:20250000F100100800140404080C10BB00000004001C0000140804000800040004040C0453:2025800004CA0C080004000C040C0C04BF0000471010000000044010100000140008000083:202600000004B43800000D002AA80000AC0000B00000AC000C00080C040000530001001457:202680000000B004000000B0A801000400B001B0020000B0010C0C00002200010895001C21:2027000000FB0000AC0C040000AC000C0000ACA801000400AC01AC020000AC040C040000D6:2027800000B0AC00070000AC0C0001010000041E04000000B0AC00070000AC0C00010100D9:2028000000041E08000000ED5B0808000001ED540808000002ED4D0808000003ED4600085A:20288000001E01032B032F10081010181810FB1010010C0D0C1003040401060808010208C3:202900000801010402010101B2B20100B2B20101010101010103F9011302CB040704B42311:20298000B204F9040102B2B202010101010409040423032302230104F50401010101FB0196:202A00001000003C040400000004000004EC00E8003C00CC0000090C0C0500040405041E29:202A8000040000F2001E8010000C0010000A0004050000040003060204000004F000041048:202B000070001812000000B7F0003C070304E000FF0000D803003C00700304F405B4060802:202B80000506040400BF00000100003C0470700060700000008938003C30040C0300070328:202C00000001000403F8FF03040036F0810001310001000404050000008C0000008C0000AF:202C80000A0006056D00000C040003140006066200000C0409065B055900000C000C08061F:202D00000063003C70F00004000103017200560000029A00F0000027B0003C00B407860300:202D800004003201093E092F7C84000601040004168C140C0904101A08030100070013014E:202E00000005040400051E1B083500000807068F075B003C05B63CBA09080901000504040F:202E800001000449003C07F0F000010131046802050003010A003D0000C528003C07030499:202F0000182000050016040A000C04070C09080103070C08FA00040200EB010003003C00D2:202F8000F0B001070004020A00BB08000C0003090400B2003C07F0109004C4000010032119:2030000000100104FC108800807C848CFC1E001E00FBFE4C1000003C3C000001043C28008D:2030800000003C18003CE810889C988C01030700010103FB00011EFF01041201080D0110F9:20310000081001010F0F1210FC100802040402B20100011E08000000000000080C04000043:0F318000040000000C0E08040008000406000EF6:2033AC000000007C001800540068000000F4009C00F400F40000005800AC00940000003071:20342C000084006C0000006C009C0000000800E4000000E000A8000000B400F40000006C00:1634AC0000F4000000C00000001C00000098000000D0000000785A:203504000468B5046CE50470D90474010478E90C3C1A03000448000C5C004C18047C000405:2035840080000484010488B8048CB8049034049400049800049C0004A00304A40004A800FB:0136040000C5:02360800400080:00000001FF";
	cb->byte1 = ":020000040002F8:200000000000004000000600000050000000064000FF80001000002000303020FF20003086:200080003020FF2020002000FFFFFF3635C0000010001006FF4000C000000006000000C09E:2001000000000010000080401000C00000001000C0CF00000680400000008034401000C016:2001800000000006000000C00000100020000080401000C00000001000C0CF000006804074:2002000000000180344030201000C0C00000041006041006100006C0001006C0001006C053:200280000000C0001006C0001006C0001006C000C0100600C000C01006008040201000C000:2003000000000005000000C00300C002CD00C2C0C0C0020D00C000C000C0C000C00300C0F2:200380000300C00300C00300C0030000C00300C00200C00200C00200C0020000C00200C0C4:200400000200C00200C00200C0020000C00200C00200C00200C00200C0020000C00200C048:200480000200C00200C00200C0020000C00200C00200C00200C00200C0020000C0C0C0FF0B:20050000C0FFC0FFC0FFC0FFC0FF0000113020FF0000113020FF0000113020FF00C0C0FF81:20058000C0FFC0FF0080401000C00000C0CF00000580D000C0C000CC0000C0D0FFD000C0FE:20060000C000CC0000C0D0FF4000C000C01005804000C0C0C0C00000C000C010050000C0D5:2006800000C010050000804C4C340000000000000000000020202020204040404040606099:2007000060606080808080802A20401000C000000004000000C00000100020FE008040101D:2007800000C000000010FFC0CF00000480400000FF80400000FF80400000FF80400000FFFB:200800008034401000C000000004000000C00200C000C0C0C000C0C0C000C0C0C000C0C04E:20088000C000C0C0C000C0C0C000C0C0C000C0C00080401000C000000004000000C0020002:200900001000FF008040201000000010FF00C00010FF000010FF00C000FFC0FFFF804000AE:20098000C000000004000000C001000010FFC01000FF0080401000C00000C01000FF001085:200A0000FFC0CF00000480D000D0FF40D01000200010FF00FF0010FFD08040D01000200038:200A800010FF00FF0010FFD08040D01000200010FF00FF0010FFD08040D01000200010FFED:200B000000FF100000FF00D0803434344000C000000003000000C000000080401000C00088:200B800000C0CF0000038040D0100000FD00FD00C000FF0010FDD0803440D01000000400B5:200C0000C0C0C0C0C0C000C01000FF00C01000FF00C01000FF00000400C01000FF00001004:200C80000200C000FFC0FFC0FFC0FFFFD0804000C0000000030000000002C00000C000FF83:200D00000080401000C00000C01000FF001002C0CF00000380344000C00000000300000019:200D8000C0060000000080401000C00000001000C0CF000003804000C00000000300008058:200E0000401000C0000000030000804020100000038040100000100080401000000080405C:200E80001000C0000000030000804020100000100080401000000080401000C0000000021D:200F0000000080D00000D0FFD000C000D0FF4000C00000000200000000FF1000000000C082:200F800000C000000080401000C000000000C0CF000002804000C000FFC0C0C000FFC0C032:20100000C0C000FFC0C0C0C000000000FFC0C01000FF001020FFC0C0C000C000FF804000D5:201080000010FF00C0C000FFC0102000FFC0C0C000FFC0102000FFFF0080400000FFC00027:20110000FFC01000FFC000FFC01000FFC0001020FFC0000080401000C00101028040100060:20118000C0C0100002000000C000C0C0FF0080D000D0FFD000D0FF401000C00000000200AE:2012000000000010FF0080401000C0000000020000001000FE1000FFC01000FF0080401071:2012800000C0000000020000001000FE1000FFC01000FE00804000C000000002000000001F:20130000FEC000000080401000C000000010FEC0CF00000180D00000D0FFD00000D0FFD053:2013800000D0FF656C726533331640D01000000200C0C000C00010C10000C0C0C0C0000225:20140000C000FFC0C0C00000022010000000C000FFC0FFD0804000C1C000002110013002A8:2014800001C0C0FF8040D0201000C1C0C0C000C00000000200FF001002C0C0C0C0C0C0C0F8:201500000000FFD08040D0201000C1C0C0C000C00000000200FF00C0100002C0C0C0C000A8:2015800000FF00D0804000C0000000010000000000C0000000FF0080401000C0000000109C:2016000000C0CF000001804000FF00001000FF804000FF0002803333003433334000C0002B:201680000000010000000000C000000080401000C00000001000C0CF00000180340002D0D3:201700001000D0FF4000C000000000000000C00000C00000C00003C0000080401000C00057:2017800000C0CF000000804000C0000300C0C0C0C01000100010C0FFC010002003FF340022:20180000D000D0FFFF4000C00000000000000000FFC000000080401000C000000010FFC00C:20188000CF00000080D000C000D0FFD01000D0FF33004000000000100000804000C00000E8:20190000000000000000FFC000000080401000C000000010FFC0CF00000080D000C000D0FA:20198000FFD01000D0FF40000003C0C0C0000000C0C0C000C000FF0003C0C0C00000FFC015:201A0000C0C000C000FFFF3400384050C04000010010200000001003C00048480001FF8078:201A80000000FFC040E0FF47C000FFC000FFFF333340D000FC00FF1000FCD00080405060E7:201B0000705000034000800040FF00FF0080333000FF04FFD01000C00010200000D0FFD0B0:201B80001000C00010200000D0FFD01000C00010200000D0FFD0100010C010200C000000EB:201C0000D0FFD0201000D0FF4030201000C0000000FF00000000C0C000C0C000C0C0000047:201C800080D000C000D0FFD000C000D0FFD000C000D0FF00FFD000C0C0C0000000C00000D8:201D0000C0C0C0C0C000FFD0FFD000C00000D0FF400000FF00FF80D0100000C0C0D0FF40A9:201D8000000010FF8040000010FF8040000010FF80D0100000C0C0C000C0C4C0D0FFD01003:201E00000000C0C0D0FFD01000C000100000C010000000D0FFD0100000C000000000C000C4:201E8000000000C000FFFFD0FFD01000FFC0000000FFD0FF40D0100000C00000C0000000A8:201F0000C00000000010FF0010FF0010FFD080D0100000C0C0D0FFD000C0000000D0FFD026:201F800000C0000000D0FFD000C00000D0FFD000C0000000D0FF40D03020100000C00000C4:2020000000FF00FF1000FF0010FF0010FF0010FFD080D000C0C0C0C0C000000000D0FFD007:2020800000C0C0C0C0C000000000D0FFD01000C000C0C0D0FFD01000C000C0C0D0FF404053:2021000000008050C000000000000000C010FF00C0FF0000FF80C010C010C0C000FF33339D:202180003320034000001000001000FE00000000010000C0C0008040D01000C0C0C000002A:202200001000000010200000FFC0C0000000C0C010000000C00000C000001000FE000000E1:2022800010002003C0000000C0C0C000D080D0100000C000C000D0FFD01000C000D0FFD04D:20230000201000C0C00000C0C0000000C0000000000000D0FF40D01000C0C0C01000FE0090:2023800000000010200000000000D08040D0201000C0000000FD00000000C0C000C0C0C000:202400001000FE00000010002003C000C0C0C00000C0000000FFC00000D080D000C000D04C:20248000FFD000C000C00000D0FF40D030201000C00011FF00C0001021000010FF001000CE:20250000FD00000000C01000203000FD0000C0C000D08040D0201000C00000C000C0C0C0D1:2025800000FD00C00000C000C0C0C000FD1000FF00C000000010FF00C00000D0804000C093:20260000000000FD000000C00000C00000C00000C000C0101100804010000000000000000C:20268000C01000C0C100C000C0000000C000000000C0000000804000000000000002000027:2027000000FFC000C0C1C0C000C0101100C000C0000000C000000000C000000080D000C008:2027800000C0000000C000C0C10000000000D0FFD000C000C0000000C000C0C100000000D8:2028000000D0FF400010200002804000102000028040001020000280400010200002008021:2028800000FF400000000000000020505020FF002080300020C0F1303080001010800050A9:2029000050802030F23030803030800030303030803030208000FF000000FF2000303038EF:202980003020FF008020303020203030802000303034303430343020FF2080303020FF805E:202A0000C6C040FF06C600C6C0C0C0C0C005C0C5C0FF801520C00000200000C0C000C0FF82:202A8000C000C0FFC0FF1540C02000003000E00000000020C000003020004000FFC0C08044:202B00004040C500C00000FFC4C0FFC0C060C450FF00304400C0FF00800050FF00FFC0007A:202B8000000000C0C0FF60C0C0C0C0FF00804050C480C00000FFC4C0FFC4503000600060BD:202C00000000003000FFFF00441000032F0010001010C050C0005000C0CF6000C0CF5000E2:202C800000000000FFC000C0C0C00000000000FFC000C0C00000FF00FFC000C000C0C000F8:202D0000C0FFC0FF80437050C3800000FF700000C000FF00830000FFC2C0FF6042C00FC00D:202D800090C0006000000000122210C0100000C0001F00C0C03000FF0000000050C000C011:202E0000C0C050C0C000FF0000FF50C0001020FE00FFC0FF00FFFFFF000000C0C0C050C01B:202E8000C0C000FFC0FF0083478040500000C10000C00000FF70000000FEC1C0FFC0C0909C:202F0000C16100100000A0C0207030C0C040C00030700040FF00000000FF000000C0FF0042:202F800087FEC000C05000C0C0FE00C0C0C00000C0C0FEC0FF0087400100FEC000801011BA:2030000020801020FF803320333333331FFF00FF40FFFFC040C040FFC0C0000000FFC0C0E9:203080000000FFC0C0FFFF803333333340000000102000FF0040FF10140000180000E0009D:20310000000040C030205030FF00004000100010001040FF400010002030008040100000C1:0F31800010203000804020100030102000008010:2033AC000000001300130013001300000016000D0016001600000018001800180000001905:20342C00001900190000000B000B0000000D000B00000015001300000016001600000017B5:1634AC0000160000000100000001000000050000000900000007DD:2035040000333B0033550033A30033000033BA003300000000330000330033130033200089:20358400332000330000331A00331A00331200330000330000330000330000330000330090:0136040000C5:023608001600AA:00000001FF";
	cb->byte2 = ":020000040002F8:200000000000002D9F70009F70009F750000009554FFBD009011005200908152FF9200D025:20008000C152FF1062809052FF2FFF02029F7CA0A09C8C00FF2D8D9D5C00A000508D009DFA:200100009F8C9DA0009DBD2D8D8D9D5C009DA0009DB0009D00BD2D8D9D00BD022D8D8D9DFF:200180005C00A000508D009D9F8C9D9DA0009DBD2D8D8D9D5C009DA0009DB0009D00BD2D39:200200008D9D00BD022DCD8D8D8D9D9C5C009FA0009FA0009D9D009D9D8C009D9D8C00DD9E:200280005C009D9D8C009D9D8C009D9D8C009D9C9D9C00009D9C9D9C008DBD2DCD8D8D9DD1:200300005C00A000508D009D9F8C9DA08C9DA08C809DA08CC04C9D809DDDC0009D9F8C9D99:200380009F8C9D9F8C9D9F8C9D9F8C009D9F8C9D9F8C9D9F8C9D9F8C9D9F8C009D9F8C9D8D:200400009F8C9D9F8C9D9F8C9D9F8C009D9F8C9D9F8C9D9F8C9D9F8C9D9F8C009D9F8C9D0C:200480009F8C9D9F8C9D9F8C9D9F8C009D9F8C9D9F8C9D9F8C9D9F8C9D9F8C009D9C5CFF5D:200500005CFF5CFF5CFF5CFF5CFF009D9FDDA0FF009D9FDDA0FF009D9FDDA0FF009D5CFFF4:200580005CFF5CFF9DBD2D8D8D9D5C009DB0009D00BD4D8D9D9CA0A09D90808D2F4D8D9D31:200600009CA0A09D90808D2F2D8D9D9C9D9C00BD2D8DA0CD9DDC5C009D9C9D9C00CD009DD4:200680009C9D9C00CDDDBD00000231313131310505050505050505050505050505050505D2:20070000050505050505050500002D8D8D9D5C00A000508D009D9F8C9D9DA0FF9DBD2D8D3F:200780008D9D5C009DA0FF9DB0009D00BD2D8D9DFFBD2D8D9DFFBD2D8D9DFFBD2D8D9DFF61:20080000BD022D8D8D9D5C00A000508D009D9F8C9D9D9C809D9D9C809D9D9C809D9D9C803C:200880009D9D9C809D9D9C809D9D9C809D9DDCC09DBD2D8D8D9D5C00A000508D009D9F8CA1:200900009D9DFF9DBD2DCD8D8D009D9DFF009D9D8CFF009D9DFF00DD5CFF5CFFFFBD2D8DF0:200980009D5C00A000508D009D9F8C9DA0FF9DA08CFF9DBD2D8D8D9D5C009DA08CFF9DA076:200A0000FF9DB0009D00BD4D8D8D2F2D4DCD8DDD9D8DFF8DFF8DA0FF8DBD2D4DCD8DDD9D70:200A80008DFF8DFF8DA0FF8DBD2D4DCD8DDD9D8DFF8DFF8DA0FF8DBD2D4DCD8DDD9D8DFF12:200B00008DFFA0CD8DFFDD8DBD0202022D8D9D5C00A000508D009D9F8C9DBD2D8D8D9D5C91:200B8000009DB0009D00BD2D4D8D8D8DFF8DFFCDDD5CFF8DA0FF8DBD022D4D8D8D9D008DC7:200C00009DDCCD9DDCCD009DDD8CFF009DDD8CFF009DDD8CFF009D008D9DDD8CFF8D9D8D53:200C80000000DD5CFF5CFF5CFF5CFFFF8DBD2D8D9D5C00A000508D009D009D9F8C9D8CFF05:200D00009DBD2D8D8D9D5C009DA08CFF9DA0009DB0009D00BD022D8D9D5C00A000508D005B:200D80009D9F8C9D009DBD2D8D8D9D5C009DA0009DB0009D00BD2D8D9D5C00A0008D9DBD36:200E00002D8D8D9D5C00A0008D9DBD2D8D8D8D9D00BD2D8D8D9DA000BD2D8D8D9D00BD2DCE:200E80008D8D9D5C00A0008D9DBD2D8D8D8D9D9D00BD2D8D8D9D00BD2D8D8D9D5C00A0006C:200F00008D9DBD4D8D9D8D2F4D8D9D8C8D2F2D8D9D5C00A000508D008DFFA09D009D009DC5:200F80008C9DA08C9DBD2D8D8D9D5C009D009DB0009D00BD2D8D9D9CFF908D9D9CFF9D9C9E:20100000809D9CFF9D9C809DA08C009DFF908D9D9DFF9D9DA0FF9D8D9D9D9C5CFFBD2D8DF9:201080009DA0FF8DA08D9DFF9DA08D8CFF9D8C8D9DFF9DA08D8CFFFF9DBD2D8D9DFF9D9CDA:20110000FF9DA08CFF9D9CFF9DA08CFF9D9D9CA0FF9DA08CBD2D8D8D9DA08000BD2D8D8D05:201180009D8D9DA000508D009D9D9C80FF8DBD4D8D8D2F4D8D8D2F2D8D8D9D5C00A0005010:201200008D009D9DFF9DBD2D8D8D9D5C00A000508D009D8DFFA09DFF9D9D8CFF9DBD2D8DB3:201280008D9D5C00A000508D009D8DFFA09DFF9D9D8CFF9DBD2D8D9D5C00A000508D009DFA:20130000FF9D9F8C9DBD2D8D8D9D5C009DA0FF9DB0009D00BD4D8D8F8D2F4D8D9F8D2F4DE2:201380008D8D2F725F76000202022D4D8D8D9D008DA08D009D9D9DD09D40C19D8C8D9D0034:201400009D50FF9DDCCD009D009D409D0000DD5CFF5CFF8DBD2D8D9F9C5C009FA09FA000D7:201480009FA080FFBD2D4D8D8D8D9F8DA08D9D9D5C009D0050FF9D9D009D8C8D9D8C8D9D92:201500009D5CFF8DBD2D4D8D8D8D9F8DA08D9D9D5C009D0050FF9D9D809D009D8C8D9D9D46:201580005CFF9D8DBD2D8D9D5C00A000508D009D009D9F8C9DFF9DBD2D8D8D9D5C009DA001:20160000009DB0009D00BD2DA0FFA000A0A0FFBD2D9FFF9F00BD0202020202022D8D9D5CD5:2016800000A000508D009D009D9F8C9DBD2D8D8D9D5C009DA0009DB0009D00BD02A0004DFB:201700008D8D8D2F2D8D9D5C00A000508D009D9F8C9D9F8C9D9C009D8C9DBD2D8D8D9D5C37:20178000009DB0009D00BD2D8D9D9C008D9D9C8C8D9D9DD1819D9C2F9D9D9CA000FF020065:201800004D8D8D2F2F2D8D9D5C00A000508D009DFF9D9F8C9DBD2D8D8D9D5C009DA0FF9DFC:20188000B0009D00BD4D8D9F9C8D2F4D8D8D8D2F020F2DA000A000A0A000BD2D8D9D5C001C:20190000A000508D009DFF9D9F8C9DBD2D8D8D9D5C009DA0FF9DB0009D00BD4D8D9F9C8DC7:201980002F4D8D8D8D2F2D8DA000A08D9D9F50009D8C8D9F9D50FFA000A08D9D9F50FF9DAC:201A00008C8D9F9D50FFFF0210012DA0D5A000808580915200919100D584A0A05CA0FFBDF3:201A800014002FA0A08F2FC09F8C2F9F8C2F2F02022D4DA0FFA0FFA0A0FF8DA0BD2DB09F01:201B00009FA0A0009750BD54A02F56FFA0BD0202502F002F4D8D8D9D9D9CA0818C8D2F4DC8:201B80008D8D9D9D9CA0C18C8D2F4D8D8D9D9D9CA0218C8D2F4D8D8D9D9D91A011A000A043:201C00008D2F4D8D8D8D8D2F2D8D8D8D8D9D5C00A0FF508D009D9D809D9D809D9D809D8D2A:201C8000BD4D8D9D9C8D2F4D8D9D9C8D2F4D8D9D9C8D2FA02F4D8DA08D9D9C808C9D5C0006:201D00009D9C0C8D9D5CFF8D2F4D8D9DA08C8D2F2D8D9DFF9DFFBD4D8D8D9D9D808D2F2D25:201D80008D9DA0FFBD2D8D9DA0FFBD2D8D9DA0FFBD4D8D8D9D9D0C809D9DA0808D2F4D8D3A:201E00008D9D9D808D2F4DCD8D9DDD9CC18C9DDD9C818C8D2F4DCD8D009D9CC08C009D9C71:201E8000808C00DD5CFFFF8D2F4D8D8DFF9D9CC08CFF8D2F2D4D8D8D9D8D908C9D9CC08C3E:201F00009D9CC08C9DDDFF9DDDFF9D9DFF8DBD4DCD8D9DDD808D2F4D8D9D9C808C8D2F4D42:201F80008D9D9C808C8D2F4D8D9DA08C8D2F4D8D9D9C808C8D2F2D4DCD8D8D8D9D8D908C45:202000009DFF9DFF9D9DFF9DDDFF9D8DFF9D9DFF8DBD4D8D9D9C0C8D9D5CA000A08D2F4D3C:202080008D9D9C0C8D9D5CA000A08D2F4D8D8D9D9DDC808D2F4D8D8D9D9D9CC08D2F2D9FAE:202100009450BD9FA09C849C500055009CA02F009C2F9450FFBD9F9F819F9180812F020285:202180000202002D8D9DA0008D9DA0FF508D009D0000A09D9C8CBD2D4D8D8D9D9C8D009DE8:202200009D008D9D9D9D0050FF9D9C5C009D9D809D9D008D9DA08C9DA08C9DA0FF508D00AD:20228000A09DA0009DA08C9D9D809D8C8DBD4D8D8D9D9D90808C8D2F4D8D8D9D4C8D2F4D19:202300008D8D8D9D9C5C009D9C5C009D9D905C00A000A08D2F2D4D8D8D9D8C8D9DA0FF50F4:202380008D009D9D9D0000A08D9D8DBD2D4D8D8D8D9D5C00A0FF508D009D9D809D9D809D1E:202400009CA0FF508D00A09DA0009D00A08D9DA08C9DA08C9DFF9D8C9D8DBD4D8D9D9C8D1F:202480002F4D8D9D9D9C90408D2F2D4D8D8D8D8D9D9DA0FF8D9D9D9DA0009DA0FF8D9DA040:20250000FF508D009D9D9D909D809DFF00A09D9C8C8DBD2D4DCD8D8DDD5C009D9D9C408DD3:202580009DFF8DDD5C009D9D9C408D9DFFA09DFF8D9DA08C9D9DFF8D9DA08C8DBD2D8D9DD8:202600005C00A0FF508D009DA08C9DA08C9DA08C9D9D9CA0809DBD2D8D8D9D005000A00063:202680009D9D9C9D819D9D909C805C009D9C808C009DA08CA0BD2D8D9D005000A0009D00B5:2027000050FF9D9D9C908D9D9D9CA0809D9D909C805C009D9C808C009DA08C9DBD4D8D9D60:202780009D9C905C009D9D9C905C00A000A08D2F4D8D9D9D9C905C009D9D9C905C00A00058:20280000A08D2F2DCDDDA0A000BD2DCDDDA0A000BD2DCDDDA0A000BD2DCDDDA0A000A0BD6C:20288000522F2D1100100052002D42B1A052FFBD92BD1200D24F8C9180BD00B1A0BD00B1AE:20290000A0BD524F83D1C0BDD1C0BDA0D1C0D1C0BDD1C052BD11FF100010FF520091C0A009:202980004052FF72BD92D1C04292D1C0BD520091C0A040A040A04052FF92BDD1C052FFBDB0:202A00009F9C2D2F9F9F8C9F9C4C80A0809F809F9C2FBD9FA0910050A00052909000822F05:202A8000925CA0FF812F9F2D91B08100A000905E00538180A0A000A093529283FFA080BDD3:202B00002DB09F009C5C00FF9F9C2F84CC4C9F9CFF55959F00942FA0BD5695FFA0FF435C31:202B80000085804C80FF85958C85942F85BD2DB09FBD9C5C00FF9F9C2F9F45A055A000A082:202C000096C0838055FFFF559F93009FB090C10083838C814C5CA05696B0A05595B0A056BA:202C8000005500A0FF9395808C83A0005500A0FF9693808C00A0FFA0FF96938095808CA098:202D000086FF942FBD2DB0479FA000A0FFA000589C00FFA0BD5C00FF9F9C2F959F88B0CCBF:202D80004C940046560056009F9F9185828C519C00B000864C9C00FF53898085A094008957:202E000085898C4385A0FF00A0FFB09400A0A0FFA0FF942FA0FF2FFF4650008985898C4067:202E80008C8585FF942FA0BD2DA0B04800589F00189C00A0FFA0005C00FF9F9C2F84CC4C6D:202F00009F9F9CE0500080859001474A824C800088885344FF54900050FF005000962FA0A4:202F8000BDFF895A8347004580FF5495848500874480FF962FA0BD2D04A0FFB0A0BD84B095:20300000A0BD518CFFBD020002020202002FA02F2DFFFF9F2D9CA02F9F9C5C00A02F9F9CAF:203080005C002F9F9C2FFFBD020202022D100052C05210FF52BD2F01815200815200A052F0:20310000002DA0A04202A053FFBD12A0128012C012C0BD2F2D8DA09DA0A000BD2D8D8D9DA3:0F3180009DA0A000BD2D8D8D8D9D9D9DA000BD9E:2033AC000000000200020002000200000002000200020002000000020002000200000002E9:20342C0000020002000000020002000000020002000000020002000000020002000000026A:1634AC0000020000000200000002000000020000000200000002FE:2035040000021200029A0002F600020000026C000200000000020000020002020002000083:2035840002000002000002020002020002000002000002000002000002000002000002000D:0136040000C5:023608000200BE:00000001FF";
	cb->byte3 = ":020000040002F8:2000000010EBEBE9E5E31BE5E31BE5E30AEAEBE4E31AE8EAE4E31AE24AE4E4E25AE20AE410:20008000E4E21AE21210E4E31AE1FF0000E5E303011512EAFFE9E5E5E31AE3EBE3E50AE5AA:20010000E5E5E5E3EBE5E8E9E5E5E5E30AE5E3EBE5E10AE5EBE8E9E5E5EBE800E9E5E5E5B7:20018000E31AE3EBE3E50AE5E5E5E5E5E3EBE5E8E9E5E5E5E30AE5E3EBE5E10AE5EBE8E905:20020000E5E5EBE800E9E5E5E5E5E5E5E31AE5E3EBE5E3EBE5E5EBE5E5E2EBE5E5E2EBE5CF:20028000E30AE5E5E2EBE5E5E2EBE5E5E2EBE5E5E5E5EBEAE5E5E5E5EBE5E8E9E5E5E5E57A:20030000E31AE3EBE3E50AE5E5E5E5E1E0E5E1E2E5E5E1E0E3E0E5E5E5E5E5EAE5E5E5E5FE:20038000E5E5E5E5E5E5E5E5E5E5E5EAE5E5E5E5E5E5E5E5E5E5E5E5E5E5E5EAE5E5E5E5B3:20040000E5E5E5E5E5E5E5E5E5E5E5EAE5E5E5E5E5E5E5E5E5E5E5E5E5E5E5EAE5E5E5E532:20048000E5E5E5E5E5E5E5E5E5E5E5EAE5E5E5E5E5E5E5E5E5E5E5E5E5E5E5EAE5E5E20A90:20050000E20AE20AE20AE20AE20AEAE5E5E5E3EBEAE5E5E5E3EBEAE5E5E5E3EBEAE5E20A4F:20058000E20AE20AE5E8E9E5E5E5E30AE5E10AE5EBE8E2E5E5E5E3E1E5E5E5E2E1E2E5E536:20060000E5E3E1E5E5E5E2E1E9E5E5E5E5E5EBE8E9E5E3E5E5E5E30AE5E5E5E5EBE5EAE50A:20068000E5E5E5EBE5E5E8484800484848484849494949494949494949494949494949493D:2007000049494949494949494848E9E5E5E5E31AE3EBE3E50AE5E5E5E5E5E3EBE5E8E9E5EA:20078000E5E5E30AE5E3EBE5E10AE5EBE8E9E5E5EBE8E9E5E5EBE8E9E5E5EBE8E9E5E5EB37:20080000E800E9E5E5E5E31AE3EBE3E50AE5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5BC:20088000E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E8E9E5E5E5E31AE3EBE3E50AE5E5E557:20090000E5E5EBE5E8E9E5E5E5EAE5E5EBEAE5E5E2EBEAE5E5EBEAE5E30AE20AEAE8E9E5B6:20098000E5E31AE3EBE3E50AE5E5E5E5E3EBE5E3E2EBE5E8E9E5E5E5E30AE5E3E2EBE5E32F:200A0000EBE5E10AE5EBE8E2E5E2E1E9E2E5E5E5E5E2EBE2EBE2E3EBE2E8E9E2E5E5E5E507:200A8000E2EBE2EBE2E3EBE2E8E9E2E5E5E5E5E2EBE2EBE2E3EBE2E8E9E2E5E5E5E5E2EBA3:200B0000E2EBE3E5E2EBE5E2E8000000E9E5E5E31AE3EBE3E50AE5E5E5E5E8E9E5E5E5E37D:200B80000AE5E10AE5EBE8E9E2E5E5E2EBE2EBE5E5E30AE2E3EBE2E800E9E2E5E5E5EBE519:200C0000E5E5E5E5E5E5EAE5E5E2EBEAE5E5E2EBEAE5E5E2EBEAE5EBE5E5E5E2EBE5E5E211:200C8000EBEAE5E30AE20AE20AE20AEAE2E8E9E5E5E31AE3EBE3E50AE5EBE5E5E5E5E2EBB4:200D0000E5E8E9E5E5E5E30AE5E3E2EBE5E3EBE5E10AE5EBE800E9E5E5E31AE3EBE3E50A61:200D8000E5E5E5E5EBE5E8E9E5E5E5E30AE5E3EBE5E10AE5EBE8E9E5E5E31AE3EBE5E5E817:200E0000E9E5E5E5E31AE3EBE5E5E8E9E5E5E5E5EBE8E9E5E5E5E3EBE8E9E5E5E5EBE8E9CB:200E8000E5E5E5E31AE3EBE5E5E8E9E5E5E5E5E5EBE8E9E5E5E5EBE8E9E5E5E5E31AE3EB23:200F0000E5E5E8E2E5E5E2E1E2E5E5E2E2E1E9E5E5E31AE3EBE3E50AE2EBE1E5EBE5EBE5DC:200F8000E5E5E3E5E5E8E9E5E5E5E30AE5EBE5E10AE5EBE8E9E5E5E5EBE5E5E5E5EBE5E549:20100000E5E5E5EBE5E5E5E5E3E5EAE5EBE5E5E5E5EBE5E5E3EBE5E5E5E5E5E11AE8E9E5DF:20108000E5E3EBE5E3E5E5EBE5E1E2E2EBE5E2E5E5EBE5E1E2E2EBEAE5E8E9E5E5EBE5E59B:20110000EBE5E1E2EBE5E5EBE5E1E2EBE5E5E5E3EBE5E3E5E8E9E5E5E5E1E0EBE8E9E5E518:20118000E5E5E5E3EBE3E50AE5E5E5E5EAE5E8E2E5E2E1E2E5E2E1E9E5E5E5E31AE3EBE35B:20120000E50AE5E5EBE5E8E9E5E5E5E31AE3EBE3E50AE5E2EBE1E5EBE5E5E2EBE5E8E9E593:20128000E5E5E31AE3EBE3E50AE5E2EBE1E5EBE5E5E2EBE5E8E9E5E5E31AE3EBE3E50AE5EB:20130000EBE5E5E5E5E8E9E5E5E5E30AE5E3EBE5E10AE5EBE8E2E5E2E2E1E2E5E5E2E1E2E9:20138000E5E2E169536900000000E9E2E5E5E5EBE5E3E5EAE5E5E5E7E5E2E7E5E2E5E5EBC4:20140000E5E1CAE5E5E5EAE5EBE5E2E5EBEAE5E30AE20AE2E8E9E5E5E5E31AE5E3E5E3EBBA:20148000E5E3E5EAE8E9E2E5E5E5E5E5E3E5E5E5E1DAE5EBE30AE5E5EBE5E2E5E5E2E5E58D:20150000E5E1CAE2E8E9E2E5E5E5E5E5E3E5E5E5E1DAE5EBE31AE5E5E0E5EBE5E2E5E5E523:20158000E1CAE5E2E8E9E5E5E31AE3EBE3E50AE5EBE5E5E5E5EBE5E8E9E5E5E5E30AE5E338:20160000EBE5E10AE5EBE8E9E1EBE1EBE3E1EBE8E9E5EBE5EBE8000049000000E9E5E5E3EF:201680001AE3EBE3E50AE5EBE5E5E5E5E8E9E5E5E5E30AE5E3EBE5E10AE5EBE800E3EAE2D5:20170000E5E5E2E1E9E5E5E31AE3EBE3E50AE5E5E5E5E5E5E5E5EBE5E5E5E8E9E5E5E5E3C7:201780000AE5E10AE5EBE8E9E5E5E5EBE5E5E5E2E5E5E5E1E0E5E5E1E5E5E5E3EBEA002001:20180000E2E5E2E1E1E9E5E5E31AE3EBE3E50AE5EBE5E5E5E5E8E9E5E5E5E30AE5E3EBE5A4:20188000E10AE5EBE8E2E5E5E5E2E1E2E5E5E2E10082E9E1EBE1EBE3E1EBE8E9E5E5E31A98:20190000E3EBE3E50AE5EBE5E5E5E5E8E9E5E5E5E30AE5E3EBE5E10AE5EBE8E2E5E5E5E2A8:20198000E1E2E5E5E2E1E9E5E3EBE3E5E5E5E1DAE5E2E5E5E5E1CAE3EBE3E5E5E5E1DAE5ED:201A0000E2E5E5E5E1CAEA008200E9E1E1E3EAE0E0E2E5E30AE5E5EBE1E2E1E1E1E1CAE884:201A8000E31AE1E1E1E2E146E5E5E1E5E5E1E10000E9E2E1EBE1EBE3E1EBE2E3E8E9E1E5F8:201B0000E503E1EBE5E318E301E1E11AE3E80000E301EAE1E2E5E5E5E5E5E3E1E5E2E1E24E:201B8000E5E5E5E5E5E3E1E5E2E1E2E5E5E5E5E5E3E0E5E2E1E2E5E5E5E5E5E3E1E30AE3AB:201C0000E2E1E2E5E5E5E2E1E9E5E5E5E5E5E31AE3EBE3E50AE5E5E5E5E5E5E5E5E5E5E5D7:201C8000E8E2E5E5E5E2E1E2E5E5E5E2E1E2E5E5E5E2E1E1E1E2E5E3E5E5E5E3E5E5E30AAB:201D0000E5E5E2E5E5E31AE2E1E2E5E5E3E5E2E1E9E5E5EBE5EBE8E2E5E5E5E5E5E2E1E9F9:201D8000E5E5E3EBE8E9E5E5E3EBE8E9E5E5E3EBE8E2E5E5E5E5E2E5E5E5E1E5E2E1E2E59A:201E0000E5E5E5E5E2E1E2E1E5E5E1E5E1E5E5E1E5E1E5E2E1E2E1E5EAE5E5E3E5EAE5E546:201E8000E3E5EAE1E30AEAE2E1E2E5E5EAE5E5E3E5EAE2E1E9E2E5E5E5E2E8E8E5E5E3E582:201F0000E5E5E3E5E5E1EBE5E1EBE5E5EBE2E8E2E5E5E5E5E5E2E1E2E5E5E5E3E5E2E1E232:201F8000E5E5E5E3E5E2E1E2E5E5E3E5E2E1E2E5E5E5E3E5E2E1E9E2E5E5E5E5E5E2E8E8BE:20200000E5EBE5EBE5E5EBE5E5EBE5E2EBE5E5EBE2E8E2E5E5E5E2E5E5E3E31AE3E2E1E2E0:20208000E5E5E5E2E5E5E3E3DAE3E2E1E2E5E5E5E5E5E5E2E1E2E5E5E5E5E5E5E2E1E9E5CB:20210000E5E308E5E1E5E5E5E30AE10AE5E3E1EAE5E1E5E31AE8E5E5E5E5E5E5E5E100005B:202180000000EAE9E5E5E3EBE5E5E3EBE3E50AE5EBEAE3E5E5E0E8E9E2E5E5E5E5E5EAE528:20220000E5EBE5E5E5E5EBE30AE5E5E31AE5E5E5E5E5EBE5E5E3E5E5E3E5E5E3EBE3E50A93:20228000E3E5E3EBE5E3E5E5E5E5E5E2E2E8E2E5E5E5E5E5E0E2E2E1E2E5E5E5E2E2E1E2C3:20230000E5E5E5E5E5E31AE5E5E30AE5E5E5E1CAE3EAE3E2E1E9E2E5E5E5E2E5E5E3EBE3EC:20238000E50AE5E5E5EBEAE3E5E5E2E8E9E2E5E5E5E5E31AE3EBE3E50AE5E5E5E5E5E5E514:20240000E5E3EBE3E50AE3E5E3EBE5EAE3E5E5E3E5E5E3E5E5EBE5E5E5E2E8E2E5E5E5E2F4:20248000E1E2E5E5E5E5E5E0E2E1E9E2E5E5E5E5E5E5E1EBE5E5E5E5E1EBE5E3EBE5E5E3A8:20250000EBE3E50AE5E5E5E5E5E0E5EBEAE3E5E5E0E2E8E9E2E5E5E5E5E31AE5E5E5E0E5C4:20258000E5EBE5E5E31AE5E5E5E0E5E5EBE1E5EBE5E5E3E5E5E5EBE5E5E3E5E2E8E9E5E559:20260000E31AE3EBE3E50AE5E3E5E5E3E5E5E3E5E5E5E5E3E7E5E8E9E5E5E5EBE30AE3EA93:20268000E5E5E5E5E7E5E5E5E5E2E1DAE5E5E2E5EAE5E3E5E3E8E9E5E5EBE30AE3EBE5EB72:20270000E31AE5E5E5E7E5E5E5E5E3E7E5E5E5E5E2E1DAE5E5E2E5EAE5E3E5E5E8E2E5E5F6:20278000E5E5E5E11AE5E5E5E7E31AE3EAE3E2E1E2E5E5E5E5E5E11AE5E5E5E7E30AE3EAE3:20280000E3E2E1E9E5E5E3E3EBE8E9E5E5E3E3EBE8E9E5E5E3E3EBE8E9E5E5E3E3EBE3E8FF:20288000E301E9E31AE31AE33AE9E2E8E8E22AE8E208E20AE3E2E0E4E408EAE8E808EAE8E6:20290000E808E21210E4E4E8E0E0E8E1E0E0E4E4E8E4E4E208E31AE31AE30AE23AE4E0E1C0:20298000E1E22AE308E2202022E22424E8E23AE4E4E1E5E1E5E1E5E22AE208E4E4E21AE831:202A0000E5E5E9E1E5E5E5E5E5E2E5E3E5E5E5E5E5E1E8E5E3E5EAE1111AE305150AE5E14D:202A8000E5E3031AE5E1E5E9E5E1050AE3EAE5E18AE305151111EAE1E5E315051AE3E5E835:202B0000E9E1150AE5E30AEBE5E5E1E2E3E2E5E5EAE315E51AE5E1E3E8E1858AE1EBE0E302:202B80003AE0E2E2E5EBE5E5E3E5E5E1E2E8E9E11508E5E30AEBE5E5E1E5E2E1E1939AE17F:202C0000E5E3E0E2E18AEAE1E5051AE5E1E5130AE5E0E0E2E2E133E3151113E3151113E390:202C80001AE30AE1EBE5E5E0E2E5E1EAE31AE1EBE5E5E0E2EAE1EBE1EBE5E5E0E5E0E2E11C:202D0000E5EBE5E1E8E9E1E215E11AE1EBE1EAE3E51AEBE3E8E30AEBE5E5E1E5E5E2E1E357:202D8000E2E50AE2E10AE18AE5E5E5E0E0E2E1859AE11AE0E0E24AEBE330333531E53AE359:202E0000E5E0E2E2E5E1EBEAE1EBE1E50AE1E1EBE1EBE5E1E1EAE1EAE0E33AE3E5E0E2E2B4:202E8000E3E5E2EBE5E1E1E8E9E1E1E20AE3859AE1E50AE1EBE1EAE30AEBE5E5E1E2E3E2E4:202F0000E5E5E5E1E30AE2E0E5E0E2E0E0E0E2EAE0E0E1303AE3455AE31AEAE31AE5E1E345:202F8000E8EBE3E1E5E20AE0E5EBE33530353AE0E2E5EBE5E1E1E8E9E0E1EBE10308E2E1FD:20300000E308E2E41AE800100000000010E1E1E1E9EBEAE5E9E5E1E1E5E5E30AE1E1E5E5C4:20308000E30AE1E5E5E1EBE800000000E9E30AE38482831AE30801E2E1E33AE1E33AE1E3FA:203100003AE9E1E1E2E2E8E28AE8E318E314E310E315E8E1E9E5E3E5E3E3EFE8E9E5E5E559:0F318000E5E3E3EFE8E9E5E5E5E5E5E5E3EFE8BD:2033AC00000000000000000000000000000000000000000000000000000000000000000001:20342C00000000000000000000000000000000000000000000000000000000000000000080:1634AC00000000000000000000000000000000000000000000000A:2035040000001F000015000000000000000043000000000000000000000000000000000030:20358400001000000000000000000000000000000000000000000000000000000000000017:0136040000C5:023608000000C0:00000001FF";

	return cb;
}

