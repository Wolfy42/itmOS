
#include "TestBytes.h"

TestBytes::TestBytes() {}

CodeBytes* TestBytes::getCodeBytes()  {

	CodeBytes* cb = new CodeBytes();

	cb->byte0 = ":020000040002F8:20000000000029F09001818C01087C0104008F0400FBF0110403070403040404FB040301EC:200080000101FB0304020400EA1EFF24201401000000047BFF08000000042C8900000500B2:20010000642800071600080C040000000700021F048C0100830C0800002408E00C040000B2:20018000000428610000060068240400014C000C0C04000000070002EC048C01005A0C08DF:2002000000000C08D00F0C080400001401055C034B5403480804500804014C0804023D0C64:200280000011080403360804043D0804082E000000182904000000182E000F0E08040000C5:200300000004240100009C007C20044CA000CC0114044CA01F00001800081C5F002C0000D5:200380002404001C0800140C000C107000000000F80400F00800E80C00E0106000D4000059:20040000CC0400C40800BC0C00B4105000A80000A00400980800900C00881040007C000088:200480007404006C0800640C005C103000500000480400400800380C003010200014019B2C:2005000001A901B701C501D301E11100E80800341200D408002E0C00BC081028060407EAA9:200580008EEE01F2000E0C0400000004048C0100670C040000180110000800041E0400006B:20060000180110000C00041E08000004001863080C000004001C0006001000186004050031:200680000400185904040C0010F0343C949038343C949038343C949038343C949038343C31:20070000949038343C94903814A80C040000000428F300000600A424040000DE000C0C04FA:200780000000000700027E048C0100EC0C08000096080800007B0808000081080800008FF0:2008000008100C040000000424BB00002200E42004000000040004040400080804000C0C67:2008800004001010040014140400181804001C1C000C0C0400000004288B00000500282474:200900000400BE000C0E0804000C0400E40E000428DF090400DB050800EF01F1F50E080001:20098000000004546000000900805000955B0096285700080C040000000B0002285F000213:200A00005C048C0100520C0400041E00300400040008B1085C080245300000300400040059:200A800008A2085208023630000030040004000893083908022730000034040004000884A5:200B0000083902300817303400F01000080000000404F2000002007C0000080C0400000047:200B800004048C0100F20C0038040008470866343400FC080250380058001804000436081D:200C000008000C08040D1A000C0C8E1F000C0C7A1A000C0C9315041110000C0C9A14001061:200C80009D090D00EB01E401DD01EAFF1800080000000460900000070061006008000C1DFC:200D000000080C040000000B00020C2700005D048C0100840C700800000004106800000405:200D800000100C006800080C0400000007000275048C0100630C08000000020148000008DE:200E00000C0400000002013D00000C0E08040004470E0C04000400BC0C0C040004D40C0C27:200E80000400000002011E00000C0E0804000408AB0E0C040004B70C0C0400000002010553:200F000000000C040000041E04000004041E0C000000040CF000000B049B0000C0003E00C1:200F800004000008000C0C0400000006004B048C0100E50C0E000004C900080004C40004A7:20100000000004C30004000000080C08B5000408008600080174040800080400ED0E0E0004:2010800000016E040008049A000004017C08010804950000040172FF040E080000B50004C3:20110000810000016C00047F000001650000040139000004080C0400008C0C690C0F04007E:20118000000C0C04D600080404080000FF000F0400041E0400041E0C040000000401460090:201200000002000419000C0E040000000402360000090408EA0000DE0004011B000E0E0438:2012800000000004031F0000090408D30000D7000402CC000E080000000410090000040060:201300009400900C00080C0400000007000097048C0100040C040028041E04002C041E04A2:2013800000041E53616563F0C81C0018040004450801140914080C0C140100140114042FAB:20140000140CF00800100604260C010017041000F501FF18000800F4000008E800E400DE81:20148000D00100FF080014080400B00C0010100400100CF300FB0C08FB1001100801080425:201500001000EE14000014080400300C00101004000F0CC600FB10080C0CE2100110041016:2015800000EF10140008000000040C59000006002A009408009E00080C040000000700003E:201600002B048C0100520C0E0DDA0D5A020DE80E001C2118C9006458008868780800000005:20168000040C22000004001B00440800080C0400000007000024048C01001D0CA006AB0857:201700000400081E08000000040CFA00000A00B00800A80000004C000400080C04000000BB:2017800004048C0100F20C0E000004B308000810040400F00008043C0008005FEBB8000483:2018000000041E1E08000000040CBA00000400B300700800080C04000000070000BC048C1C:201880000100B50C04002000041E080400081E18000E0D050D2E020D110E08000000040C55:2019000084000004007D00F40800080C0400000007000086048C01007F0C0400A400041E3B:20198000080400081E0C000082000404680C0604010450040CF801730004042C0CE8040103:201A00000414040CF8E03800803000B2000C040004080003040071B20100240484EF300119:201A80000014040E011C2014001E0C001E1EA8A40800460000000030000C06000100140078:201B00000CF80127EF80F00038300105DB0000F000063404F500F0C4D8001EFA1E08040000:201B8000000400011200081E080400000400011200081E080400000400011200081E08046A:201C0000000004000112000001081E0C0804000C1E0F0C0804000000040CAA000008000457:201C800000000804000C0800000F04000000041E04000004041E04000008041E011E080070:201D0000000400540254040106005801040401F8081E0400000720041E080000E000F2085B:201D800008040000040C081E08000080F208080000BFEC0808000000E6080804000004FFBF:201E00000000044C04081E080400000420081E08B40000B40C000C00B40C000C081E08B4BC:201E80000009000C040C08000C040C03B400F2F6081E080400FF000C080CFF081E001404CC:201F00000004080707000C800C000C400C00BCBE00BECA0010DB1400080400000408081E78:201F8000040000081008041E040000104010041E0400000004041E040000101010041E00F5:202000001C18080400080C0707004D00600C00690018C4000CA600046D1C00080000140104:20208000040400000001081E0800001420040400000001081E08040004000000081E080464:202100000000040000081E307400003068000000040005000308023C01083C0000EE302480:202180001C000C0000001EC0ACB81C8C0E0000B40E0808B4C600040204F500000004000EC2:202200000014040000000C03000C2B0C00040C3700F50C04000C0C04040C001A10100000A2:202280001000040C0895000803000808670C01000C04040C0814000804000404040C080882:202300001E0804000408081E0C0804000800000A0804000408040400010100000C1E0014D7:202380000400000C0C000C53000804080C040500001010140000140804000000040CC6006F:20240000001E0004000008040000082F000C05000C08010C000010100000100004004C00A5:202480000800140004000008041E0400000004080C041E001C0C08040008000C42140814FA:202500000C0CC5000C3918180CF100100800140404080C10BB00000004001C000E04000423:20258000D400005C08080000000455080800000E0800000004B44E000008002AA80000ACF0:202600000000B000080C0400004E00120000B004000000B0A8000400B001B0020000B00C63:202680000C00002100010894001B00FB0000AC0C040000AC000C0000ACA8000400AC01AC35:20270000020000AC040C04000000B0AC00070000AC0C0001010000041E04000000B0AC0058:20278000070000AC0C0001010000041E08000000ED6F0808000001ED680808000002ED612C:202800000808000003ED5A0008001E01032B032F10081010181810FB1010010C0D0C10030B:202880000404010608080102080801010402010101B2B20100B2B20101010101010103F92F:20290000011302CB040704B423B204F9040102B2B20201010101040904042303230223014C:2029800004F50401010101FB011000003C040400000004000004EC00E8003C00CC000009F9:202A00000C0C0500040405041E040000F2001E8010000C0010000A0004050000040003068A:202A80000204000004F000041070001812000000B7F0003C070304E000FF0000D803003CA7:202B000000700304F405B406080506040400BF00000100003C0470700060700000008938FF:202B8000003C30040C030007030001000403F8FF03040036F08100013100010004040500BF:202C000000008C0000008C00000A0006056D00000C040003140006066200000C0409065B0B:202C8000055900000C000C08060063003C70F00004000103017200560000029A00F0000054:202D000027B0003C00B407860304003201093E092F7C84000601040004168C140C090410B8:202D80001A08030100070013010005040400051E1B083500000807068F075B003C05B63C31:202E0000BA090809010005040401000449003C07F0F000010131046802050003010A003D6E:202E80000000C528003C070304182000050016040A000C04070C09080103070C08FA000449:202F00000200EB010003003C00F0B001070004020A00BB08000C0003090400B2003C07F008:202F8000109004C4000010032100100104FC10A4009C98A0A8FC1E001E00FBFE4C100000C7:203000003C3C000001043C280000003C18003CE810A4B8B4A801030700010103FB00011E65:20308000FF01041201080D0110081001010F0F1210FC100802040402B20100011E00141083:2031000000000004000800000C10000000140000181410000000040008000C1014000000FB:163180001800001C181410180000040008000C14100602001C0051:2033C8000000007C001800540068000000F4009C00F400F40000005400A800900000002C65:20344800008000680000006C009C0000000800E4000000E000A8000000B400F40000006CEC:1634C80000F4000000C00000001C00000098000000D0000000783E:203520000484B50488E5048CD90490010494E90C581A03000464000C7800681804980004D1:2035A0009C0004A00104A4B404A8B404AC3404B00004B40004B80004BC0304C00004C400B3:0136200000A9:02362400400064:00000001FF";
	cb->byte1 = ":020000040002F8:200000000000004000000600000050000000064000FF80001000002000303020FF20003086:200080003020FF2020002000FFFFFF3635C0000010001006FF4000C000000006000000C09E:2001000000000010000080401000C00000001000C0CF00000680400000008034401000C016:2001800000000006000000C00000100020000080401000C00000001000C0CF000006804074:2002000000000180344030201000C0C00000041006041006100006C0001006C0001006C053:200280000000C0001006C0001006C0001006C000C0100600C000C01006008040201000C000:2003000000000006000000C00300C002CD00C2C0C0C0020D00C000C000C0C000C00300C0F1:200380000300C00300C00300C0030000C00300C00200C00200C00200C0020000C00200C0C4:200400000200C00200C00200C0020000C00200C00200C00200C00200C0020000C00200C048:200480000200C00200C00200C0020000C00200C00200C00200C00200C0020000C0C0C0FF0B:20050000C0FFC0FFC0FFC0FFC0FF0000113020FF0000113020FF0000113020FF00C0C0FF81:20058000C0FFC0FF0080401000C00000C0CF00000580D000C0C000CC0000C0D0FFD000C0FE:20060000C000CC0000C0D0FF4000C000C01005804000C0C0C0C00000C000C010050000C0D5:2006800000C010050000804C4C340000000000000000000020202020204040404040606099:2007000060606080808080802A20401000C000000004000000C00000100020FE008040101D:2007800000C000000010FFC0CF00000480400000FF80400000FF80400000FF80400000FFFB:200800008035401000C000000004000000C00200C000C0C0C000C0C0C000C0C0C000C0C04D:20088000C000C0C0C000C0C0C000C0C0C000C0C00080401000C000000004000000C0020002:200900001000FF008040201000000010FF00C00010FF000010FF00C000FFC0FFFF804000AE:20098000C000000004000000C001000010FFC01000FF0080401000C00000C01000FF001085:200A0000FFC0CF00000480D000D0FF40D01000200010FF00FF0010FFD08040D01000200038:200A800010FF00FF0010FFD08040D01000200010FF00FF0010FFD08040D01000200010FFED:200B000000FF100000FF00D0803435354000C000000003000000C000000080401000C00086:200B800000C0CF0000038040D0100000FD00FD00C000FF0010FDD0803440D01000000400B5:200C0000C0C0C0C0C0C000C01000FF00C01000FF00C01000FF00000400C01000FF00001004:200C80000200C000FFC0FFC0FFC0FFFFD0804000C0000000030000000002C00000C000FF83:200D00000080401000C00000C01000FF001002C0CF00000380344000C00000000300000019:200D8000C0060000000080401000C00000001000C0CF000003804000C00000000300008058:200E0000401000C0000000030000804020100000038040100000100080401000000080405C:200E80001000C0000000030000804020100000100080401000000080401000C0000000031C:200F0000000080D00000D0FFD000C000D0FF4000C00000000200000000FF1000000000C082:200F800000C000000080401000C000000000C0CF000002804000C000FFC0C0C000FFC0C032:20100000C0C000FFC0C0C0C000000000FFC0C01000FF001020FFC0C0C000C000FF804000D5:201080000010FF00C0C000FFC0102000FFC0C0C000FFC0102000FFFF0080400000FFC00027:20110000FFC01000FFC000FFC01000FFC0001020FFC0000080401000C00101028040100060:20118000C0C0100002000000C000C0C0FF0080D000D0FFD000D0FF401000C00000000200AE:2012000000000010FF0080401000C0000000020000001000FE1000FFC01000FF0080401071:2012800000C0000000020000001000FE1000FFC01000FE00804000C000000002000000001F:20130000FEC000000080401000C000000010FEC0CF00000280D00000D0FFD00000D0FFD052:2013800000D0FF656C726533331640D01000000200C0C000C00010C10000C0C0C0C0000225:20140000C000FFC0C0C00000022010000000C000FFC0FFD0804000C1C000002110013002A8:2014800001C0C0FF8040D0201000C1C0C0C000C00000000200FF001002C0C0C0C0C0C0C0F8:201500000000FFD08040D0201000C1C0C0C000C00000000200FF00C0100002C0C0C0C000A8:2015800000FF00D0804000C0000000010000000000C0000000FF0080401000C0000000109C:2016000000C0CF000001804000FF00001000FF804000FF0002803333003433334000C0002B:201680000000010000000000C000000080401000C00000001000C0CF00000180340002D0D3:201700001000D0FF4000C000000000000000C00000C00000C00003C0000080401000C00057:2017800000C0CF000000804000C0000300C0C0C0C01000100010C0FFC0100003FF3400D072:2018000000D0FFFF4000C00000000000000000FFC000000080401000C000000010FFC0CF0D:2018800000000080D000C000D0FFD01000D0FF34004000000000100000804000C0000000B6:201900000000000000FFC000000080401000C000000010FFC0CF00000080D000C000D0FFFB:20198000D01000D0FF40000003C0C0C0000000C0C0C000C000FF0003C0C0C00000FFC0C054:201A0000C000C000FFFF3400384050C04000010010200000001003C00048480001FF800038:201A800000FFC040E0FF47C000FFC000FFFF3333400003C0C0C0C000C00000C0C0C000C03B:201B000000FF0003FF38405060705000034000800040FF00FF0080332F00FF03FFD0100018:201B8000C00010200000D0FFD01000C00010200000D0FFD01000C00010200000D0FFD01068:201C00000010C010200C000000D0FFD0201000D0FF4030201000C0000000FF00000000C0FB:201C8000C000C0C000C0C0000080D000C000D0FFD000C000D0FFD000C000D0FF00FFD00018:201D0000C0C0C0000000C00000C0C0C0C0C000FFD0FFD000C00000D0FF400000FF00FF8018:201D8000D0100000C0C0D0FF40000010FF8040000010FF8040000010FF80D0100000C0C047:201E0000C000C0C4C0D0FFD0100000C0C0D0FFD01000C000100000C010000000D0FFD01091:201E80000000C000000000C000000000C000FFFFD0FFD01000FFC0000000FFD0FF40D010A8:201F00000000C00000C0000000C00000000010FF0010FF0010FFD080D0100000C0C0D0FFD5:201F8000D000C0000000D0FFD000C0000000D0FFD000C00000D0FFD000C0000000D0FF4085:20200000D03020100000C0000000FF00FF1000FF0010FF0010FF0010FFD080D000C0C0C036:20208000C0C000000000D0FFD000C0C0C0C0C000000000D0FFD01000C000C0C0D0FFD010C3:2021000000C000C0C0D0FF404000008050C000000000000000C010FF00C0FF0000FF80C0D3:2021800010C010C0C000FF33333321034000001000001000FE00000000000000C0C00080C5:2022000040D01000C0C0C000001000000010200000FFC0C0000000C0C010000000C000004F:20228000C000001000FE00000010002003C0000000C0C0C000D080D0100000C000C000D0BD:20230000FFD01000C000D0FFD0201000C0C00000C0C0000000C0000000000000D0FF40D0B0:202380001000C0C0C01000FE0000000010200000000000D08040D0201000C0000000FD0062:20240000000000C0C000C0C0C01000FE00000010002003C000C0C0C00000C0000000FFC03C:202480000000D080D000C000D0FFD000C000C00000D0FF40D030201000C00011FF00C0006E:202500001021000010FF001000FD00000000C01000203000FD0000C0C000D0804010000031:20258000FD1000FF00C000000010FF00C00000804000C0000000FD000000C00000C00000A3:20260000C00000008040100000000000C01000C0C100C000C00000C000000000C000008059:202680004000000000000002000000FFC000C0C1C0C000C0101100C000C00000C000000017:2027000000C000000080D000C000C0000000C000C0C10000000000D0FFD000C000C00000C9:2027800000C000C0C10000000000D0FF4000102000028040001020000280400010200002D3:2028000080400010200002008000FF400000000000000020505020FF002080300020C0F187:2028800030308000101080005050802030F23030803030800030303030803030208000FF57:20290000000000FF20003030383020FF0080203030202030308020003030343034303430E5:2029800020FF2080303020FF80C6C040FF06C600C6C0C0C0C0C005C0C5C0FF801520C000A4:202A000000200000C0C000C0FFC000C0FFC0FF1540C02000003000E00000000020C00000F4:202A80003020004000FFC0C0804040C500C00000FFC4C0FFC0C060C450FF00304400C0FFFA:202B000000800050FF00FFC000000000C0C0FF60C0C0C0C0FF00804050C480C00000FFC472:202B8000C0FFC45030006000600000003000FFFF00441000032F0010001010C050C000506E:202C000000C0CF6000C0CF500000000000FFC000C0C0C00000000000FFC000C0C00000FFA9:202C800000FFC000C000C0C000C0FFC0FF80437050C3800000FF700000C000FF0083000040:202D0000FFC2C0FF6042C00FC090C0006000000000122210C0100000C0001F00C0C03000AF:202D8000FF0000000050C000C0C0C050C0C000FF0000FF50C0001020FE00FFC0FF00FFFF1C:202E0000FF000000C0C0C050C0C0C000FFC0FF0083478040500000C10000C00000FF70005B:202E80000000FEC1C0FFC0C090C16100100000A0C0207030C0C040C00030700040FF0000F3:202F00000000FF000000C0FF0087FEC000C05000C0C0FE00C0C0C00000C0C0FEC0FF00871C:202F8000400100FEC00080101120801020FF803320333333331FFF00FF40FFFFC040C040C8:20300000FFC0C0000000FFC0C00000FFC0C0FFFF803333333340000000102000FF0040FF3B:2030800010140000180000E000000040C030205030FF00004000100010001040FF40D00086:20310000C0C0C0C0C0C010C0C000203000D08040D01000C0C0C0C0C0C0C0C000102030007F:16318000D08040D0201000C0C0C0C0C0C0C0C03010002000D080F9:2033C8000000001300130013001300000016000D00160016000000180018001800000019E9:20344800001900190000000B000B0000000D000B0000001500130000001600160000001799:1634C80000160000000100000001000000050000000900000007C1:2035200000333B0033550033A30033000033BA00330000000033000033003313003320006D:2035A000332000330000331A00331A00331200330000330000330000330000330000330074:0136200000A9:0236240016008E:00000001FF";
	cb->byte2 = ":020000040002F8:200000000000002D9F70009F70009F750000009554FFBD009011005200908152FF9200D025:20008000C152FF1062809052FF2FFF02029F7CA0A09C8C00FF2D8D9D5C00A000508D009DFA:200100009F8C9DA0009DBD2D8D8D9D5C009DA0009DB0009D00BD2D8D9D00BD022D8D8D9DFF:200180005C00A000508D009D9F8C9D9DA0009DBD2D8D8D9D5C009DA0009DB0009D00BD2D39:200200008D9D00BD022DCD8D8D8D9D9C5C009FA0009FA0009D9D009D9D8C009D9D8C00DD9E:200280005C009D9D8C009D9D8C009D9D8C009D9C9D9C00009D9C9D9C008DBD2DCD8D8D9DD1:200300005C00A000508D009D9F8C9DA08C9DA08C809DA08CC04C9D809DDDC0009D9F8C9D99:200380009F8C9D9F8C9D9F8C9D9F8C009D9F8C9D9F8C9D9F8C9D9F8C9D9F8C009D9F8C9D8D:200400009F8C9D9F8C9D9F8C9D9F8C009D9F8C9D9F8C9D9F8C9D9F8C9D9F8C009D9F8C9D0C:200480009F8C9D9F8C9D9F8C9D9F8C009D9F8C9D9F8C9D9F8C9D9F8C9D9F8C009D9C5CFF5D:200500005CFF5CFF5CFF5CFF5CFF009D9FDDA0FF009D9FDDA0FF009D9FDDA0FF009D5CFFF4:200580005CFF5CFF9DBD2D8D8D9D5C009DB0009D00BD4D8D9D9CA0A09D90808D2F4D8D9D31:200600009CA0A09D90808D2F2D8D9D9C9D9C00BD2D8DA0CD9DDC5C009D9C9D9C00CD009DD4:200680009C9D9C00CDDDBD00000231313131310505050505050505050505050505050505D2:20070000050505050505050500002D8D8D9D5C00A000508D009D9F8C9D9DA0FF9DBD2D8D3F:200780008D9D5C009DA0FF9DB0009D00BD2D8D9DFFBD2D8D9DFFBD2D8D9DFFBD2D8D9DFF61:20080000BD022D8D8D9D5C00A000508D009D9F8C9D9D9C809D9D9C809D9D9C809D9D9C803C:200880009D9D9C809D9D9C809D9D9C809D9DDCC09DBD2D8D8D9D5C00A000508D009D9F8CA1:200900009D9DFF9DBD2DCD8D8D009D9DFF009D9D8CFF009D9DFF00DD5CFF5CFFFFBD2D8DF0:200980009D5C00A000508D009D9F8C9DA0FF9DA08CFF9DBD2D8D8D9D5C009DA08CFF9DA076:200A0000FF9DB0009D00BD4D8D8D2F2D4DCD8DDD9D8DFF8DFF8DA0FF8DBD2D4DCD8DDD9D70:200A80008DFF8DFF8DA0FF8DBD2D4DCD8DDD9D8DFF8DFF8DA0FF8DBD2D4DCD8DDD9D8DFF12:200B00008DFFA0CD8DFFDD8DBD0202022D8D9D5C00A000508D009D9F8C9DBD2D8D8D9D5C91:200B8000009DB0009D00BD2D4D8D8D8DFF8DFFCDDD5CFF8DA0FF8DBD022D4D8D8D9D008DC7:200C00009DDCCD9DDCCD009DDD8CFF009DDD8CFF009DDD8CFF009D008D9DDD8CFF8D9D8D53:200C80000000DD5CFF5CFF5CFF5CFFFF8DBD2D8D9D5C00A000508D009D009D9F8C9D8CFF05:200D00009DBD2D8D8D9D5C009DA08CFF9DA0009DB0009D00BD022D8D9D5C00A000508D005B:200D80009D9F8C9D009DBD2D8D8D9D5C009DA0009DB0009D00BD2D8D9D5C00A0008D9DBD36:200E00002D8D8D9D5C00A0008D9DBD2D8D8D8D9D00BD2D8D8D9DA000BD2D8D8D9D00BD2DCE:200E80008D8D9D5C00A0008D9DBD2D8D8D8D9D9D00BD2D8D8D9D00BD2D8D8D9D5C00A0006C:200F00008D9DBD4D8D9D8D2F4D8D9D8C8D2F2D8D9D5C00A000508D008DFFA09D009D009DC5:200F80008C9DA08C9DBD2D8D8D9D5C009D009DB0009D00BD2D8D9D9CFF908D9D9CFF9D9C9E:20100000809D9CFF9D9C809DA08C009DFF908D9D9DFF9D9DA0FF9D8D9D9D9C5CFFBD2D8DF9:201080009DA0FF8DA08D9DFF9DA08D8CFF9D8C8D9DFF9DA08D8CFFFF9DBD2D8D9DFF9D9CDA:20110000FF9DA08CFF9D9CFF9DA08CFF9D9D9CA0FF9DA08CBD2D8D8D9DA08000BD2D8D8D05:201180009D8D9DA000508D009D9D9C80FF8DBD4D8D8D2F4D8D8D2F2D8D8D9D5C00A0005010:201200008D009D9DFF9DBD2D8D8D9D5C00A000508D009D8DFFA09DFF9D9D8CFF9DBD2D8DB3:201280008D9D5C00A000508D009D8DFFA09DFF9D9D8CFF9DBD2D8D9D5C00A000508D009DFA:20130000FF9D9F8C9DBD2D8D8D9D5C009DA0FF9DB0009D00BD4D8D8F8D2F4D8D9F8D2F4DE2:201380008D8D2F725F76000202022D4D8D8D9D008DA08D009D9D9DD09D40C19D8C8D9D0034:201400009D50FF9DDCCD009D009D409D0000DD5CFF5CFF8DBD2D8D9F9C5C009FA09FA000D7:201480009FA080FFBD2D4D8D8D8D9F8DA08D9D9D5C009D0050FF9D9D009D8C8D9D8C8D9D92:201500009D5CFF8DBD2D4D8D8D8D9F8DA08D9D9D5C009D0050FF9D9D809D009D8C8D9D9D46:201580005CFF9D8DBD2D8D9D5C00A000508D009D009D9F8C9DFF9DBD2D8D8D9D5C009DA001:20160000009DB0009D00BD2DA0FFA000A0A0FFBD2D9FFF9F00BD0202020202022D8D9D5CD5:2016800000A000508D009D009D9F8C9DBD2D8D8D9D5C009DA0009DB0009D00BD02A0004DFB:201700008D8D8D2F2D8D9D5C00A000508D009D9F8C9D9F8C9D9C009D8C9DBD2D8D8D9D5C37:20178000009DB0009D00BD2D8D9D9C008D9D9C8C8D9D9DD1819D9C2F9D9D9C00FF02004DB8:201800008D8D2F2F2D8D9D5C00A000508D009DFF9D9F8C9DBD2D8D8D9D5C009DA0FF9DB099:20188000009D00BD4D8D9F9C8D2F4D8D8D8D2F020F2DA000A000A0A000BD2D8D9D5C00A02C:2019000000508D009DFF9D9F8C9DBD2D8D8D9D5C009DA0FF9DB0009D00BD4D8D9F9C8D2F38:201980004D8D8D8D2F2D8DA000A08D9D9F50009D8C8D9F9D50FFA000A08D9D9F50FF9D8C4F:201A00008D9F9D50FFFF0210012DA0D5A000808580915200919100D584A0A05CA0FFBD146B:201A8000002FA0A08F2FC09F8C2F9F8C2F2F02022DA000A08DA08D9F9D50009D8C8D9F9DCD:201B000050FFA000FF012DB09F9FA0A0009750BD54A02F56FFA0BD0202502F002F4D8D8DE9:201B80009D9D9CA0818C8D2F4D8D8D9D9D9CA0C18C8D2F4D8D8D9D9D9CA0218C8D2F4D8D00:201C00008D9D9D91A011A000A08D2F4D8D8D8D8D2F2D8D8D8D8D9D5C00A0FF508D009D9DFF:201C8000809D9D809D9D809D8DBD4D8D9D9C8D2F4D8D9D9C8D2F4D8D9D9C8D2FA02F4D8D53:201D0000A08D9D9C808C9D5C009D9C0C8D9D5CFF8D2F4D8D9DA08C8D2F2D8D9DFF9DFFBDC4:201D80004D8D8D9D9D808D2F2D8D9DA0FFBD2D8D9DA0FFBD2D8D9DA0FFBD4D8D8D9D9D0CA0:201E0000809D9DA0808D2F4D8D8D9D9D808D2F4DCD8D9DDD9CC18C9DDD9C818C8D2F4DCD4C:201E80008D009D9CC08C009D9C808C00DD5CFFFF8D2F4D8D8DFF9D9CC08CFF8D2F2D4D8D4B:201F00008D9D8D908C9D9CC08C9D9CC08C9DDDFF9DDDFF9D9DFF8DBD4DCD8D9DDD808D2F12:201F80004D8D9D9C808C8D2F4D8D9D9C808C8D2F4D8D9DA08C8D2F4D8D9D9C808C8D2F2D24:202000004DCD8D8D8D9D8D908C9DFF9DFF9D9DFF9DDDFF9D8DFF9D9DFF8DBD4D8D9D9C0C04:202080008D9D5CA000A08D2F4D8D9D9C0C8D9D5CA000A08D2F4D8D8D9D9DDC808D2F4D8D8A:202100008D9D9D9CC08D2F2D9F9450BD9FA09C849C500055009CA02F009C2F9450FFBD9F5E:202180009F819F9180812F02020202002D8D9DA0008D9DA0FF508D009D0000A09D9C8CBD5B:202200002D4D8D8D9D9C8D009D9D008D9D9D9D0050FF9D9C5C009D9D809D9D008D9DA08C98:202280009DA08C9DA0FF508D00A09DA0009DA08C9D9D809D8C8DBD4D8D8D9D9D90808C8DBF:202300002F4D8D8D9D4C8D2F4D8D8D8D9D9C5C009D9C5C009D9D905C00A000A08D2F2D4DC8:202380008D8D9D8C8D9DA0FF508D009D9D9D0000A08D9D8DBD2D4D8D8D8D9D5C00A0FF5060:202400008D009D9D809D9D809D9CA0FF508D00A09DA0009D00A08D9DA08C9DA08C9DFF9D94:202480008C9D8DBD4D8D9D9C8D2F4D8D9D9D9C90408D2F2D4D8D8D8D8D9D9DA0FF8D9D9D70:202500009DA0009DA0FF8D9DA0FF508D009D9D9D909D809DFF00A09D9C8C8DBD2D8D8D9DE9:20258000FFA09DFF8D9DA08C9D9DFF8D9DA08CBD2D8D9D5C00A0FF508D009DA08C9DA08C9D:202600009DA08C9DBD2D8D8D9D0050009D9D9C9D819D9D909C5C009D9C808C009DA08CBDE2:202680002D8D9D005000A0009D0050FF9D9D9C908D9D9D9CA0809D9D909C5C009D9C808C17:20270000009DA08C9DBD4D8D9D9D9C905C009D9D9C905C00A000A08D2F4D8D9D9D9C905CA0:20278000009D9D9C905C00A000A08D2F2DCDDDA0A000BD2DCDDDA0A000BD2DCDDDA0A000BC:20280000BD2DCDDDA0A000A0BD522F2D1100100052002D42B1A052FFBD92BD1200D24F8C8A:202880009180BD00B1A0BD00B1A0BD524F83D1C0BDD1C0BDA0D1C0D1C0BDD1C052BD11FF5F:20290000100010FF520091C0A04052FF72BD92D1C04292D1C0BD520091C0A040A040A0400D:2029800052FF92BDD1C052FFBD9F9C2D2F9F9F8C9F9C4C80A0809F809F9C2FBD9FA091005A:202A000050A00052909000822F925CA0FF812F9F2D91B08100A000905E00538180A0A000B6:202A8000A093529283FFA080BD2DB09F009C5C00FF9F9C2F84CC4C9F9CFF55959F00942FC1:202B0000A0BD5695FFA0FF435C0085804C80FF85958C85942F85BD2DB09FBD9C5C00FF9F61:202B80009C2F9F45A055A000A096C0838055FFFF559F93009FB090C10083838C814C5CA023:202C00005696B0A05595B0A056005500A0FF9395808C83A0005500A0FF9693808C00A0FFD5:202C8000A0FF96938095808CA086FF942FBD2DB0479FA000A0FFA000589C00FFA0BD5C0058:202D0000FF9F9C2F959F88B0CC4C940046560056009F9F9185828C519C00B000864C9C00D3:202D8000FF53898085A094008985898C4385A0FF00A0FFB09400A0A0FFA0FF942FA0FF2F43:202E0000FF4650008985898C408C8585FF942FA0BD2DA0B04800589F00189C00A0FFA00056:202E80005C00FF9F9C2F84CC4C9F9F9CE0500080859001474A824C800088885344FF5490C8:202F00000050FF005000962FA0BDFF895A8347004580FF5495848500874480FF962FA0BD22:202F80002D04A0FFB0A0BD84B0A0BD518CFFBD020002020202002FA02F2DFFFF9F2D9CA0EF:203000002F9F9C5C00A02F9F9C5C002F9F9C2FFFBD020202022D100052C05210FF52BD2F39:2030800001815200815200A052002DA0A04202A053FFBD12A0128012C012C0BD2F2D4D8D5C:20310000A08DA08DA08DA0A08D9DA0A0008DBD2D4D8D8DA08DA08DA08DA08D9D9DA0A00072:163180008DBD2D4D8D8D8D9D8DA08DA08DA08D9D9DA0A0008DBD59:2033C8000000000200020002000200000002000200020002000000020002000200000002CD:2034480000020002000000020002000000020002000000020002000000020002000000024E:1634C80000020000000200000002000000020000000200000002E2:2035200000021200029A0002F600020000026C000200000000020000020002020002000067:2035A0000200000200000202000202000200000200000200000200000200000200000200F1:0136200000A9:023624000200A2:00000001FF";
	cb->byte3 = ":020000040002F8:2000000010EBEBE9E5E31BE5E31BE5E30AEAEBE4E31AE8EAE4E31AE24AE4E4E25AE20AE410:20008000E4E21AE21210E4E31AE1FF0000E5E303011512EAFFE9E5E5E31AE3EBE3E50AE5AA:20010000E5E5E5E3EBE5E8E9E5E5E5E30AE5E3EBE5E10AE5EBE8E9E5E5EBE800E9E5E5E5B7:20018000E31AE3EBE3E50AE5E5E5E5E5E3EBE5E8E9E5E5E5E30AE5E3EBE5E10AE5EBE8E905:20020000E5E5EBE800E9E5E5E5E5E5E5E31AE5E3EBE5E3EBE5E5EBE5E5E2EBE5E5E2EBE5CF:20028000E30AE5E5E2EBE5E5E2EBE5E5E2EBE5E5E5E5EBEAE5E5E5E5EBE5E8E9E5E5E5E57A:20030000E31AE3EBE3E50AE5E5E5E5E1E0E5E1E2E5E5E1E0E3E0E5E5E5E5E5EAE5E5E5E5FE:20038000E5E5E5E5E5E5E5E5E5E5E5EAE5E5E5E5E5E5E5E5E5E5E5E5E5E5E5EAE5E5E5E5B3:20040000E5E5E5E5E5E5E5E5E5E5E5EAE5E5E5E5E5E5E5E5E5E5E5E5E5E5E5EAE5E5E5E532:20048000E5E5E5E5E5E5E5E5E5E5E5EAE5E5E5E5E5E5E5E5E5E5E5E5E5E5E5EAE5E5E20A90:20050000E20AE20AE20AE20AE20AEAE5E5E5E3EBEAE5E5E5E3EBEAE5E5E5E3EBEAE5E20A4F:20058000E20AE20AE5E8E9E5E5E5E30AE5E10AE5EBE8E2E5E5E5E3E1E5E5E5E2E1E2E5E536:20060000E5E3E1E5E5E5E2E1E9E5E5E5E5E5EBE8E9E5E3E5E5E5E30AE5E5E5E5EBE5EAE50A:20068000E5E5E5EBE5E5E8484800484848484849494949494949494949494949494949493D:2007000049494949494949494848E9E5E5E5E31AE3EBE3E50AE5E5E5E5E5E3EBE5E8E9E5EA:20078000E5E5E30AE5E3EBE5E10AE5EBE8E9E5E5EBE8E9E5E5EBE8E9E5E5EBE8E9E5E5EB37:20080000E800E9E5E5E5E31AE3EBE3E50AE5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5BC:20088000E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E8E9E5E5E5E31AE3EBE3E50AE5E5E557:20090000E5E5EBE5E8E9E5E5E5EAE5E5EBEAE5E5E2EBEAE5E5EBEAE5E30AE20AEAE8E9E5B6:20098000E5E31AE3EBE3E50AE5E5E5E5E3EBE5E3E2EBE5E8E9E5E5E5E30AE5E3E2EBE5E32F:200A0000EBE5E10AE5EBE8E2E5E2E1E9E2E5E5E5E5E2EBE2EBE2E3EBE2E8E9E2E5E5E5E507:200A8000E2EBE2EBE2E3EBE2E8E9E2E5E5E5E5E2EBE2EBE2E3EBE2E8E9E2E5E5E5E5E2EBA3:200B0000E2EBE3E5E2EBE5E2E8000000E9E5E5E31AE3EBE3E50AE5E5E5E5E8E9E5E5E5E37D:200B80000AE5E10AE5EBE8E9E2E5E5E2EBE2EBE5E5E30AE2E3EBE2E800E9E2E5E5E5EBE519:200C0000E5E5E5E5E5E5EAE5E5E2EBEAE5E5E2EBEAE5E5E2EBEAE5EBE5E5E5E2EBE5E5E211:200C8000EBEAE5E30AE20AE20AE20AEAE2E8E9E5E5E31AE3EBE3E50AE5EBE5E5E5E5E2EBB4:200D0000E5E8E9E5E5E5E30AE5E3E2EBE5E3EBE5E10AE5EBE800E9E5E5E31AE3EBE3E50A61:200D8000E5E5E5E5EBE5E8E9E5E5E5E30AE5E3EBE5E10AE5EBE8E9E5E5E31AE3EBE5E5E817:200E0000E9E5E5E5E31AE3EBE5E5E8E9E5E5E5E5EBE8E9E5E5E5E3EBE8E9E5E5E5EBE8E9CB:200E8000E5E5E5E31AE3EBE5E5E8E9E5E5E5E5E5EBE8E9E5E5E5EBE8E9E5E5E5E31AE3EB23:200F0000E5E5E8E2E5E5E2E1E2E5E5E2E2E1E9E5E5E31AE3EBE3E50AE2EBE1E5EBE5EBE5DC:200F8000E5E5E3E5E5E8E9E5E5E5E30AE5EBE5E10AE5EBE8E9E5E5E5EBE5E5E5E5EBE5E549:20100000E5E5E5EBE5E5E5E5E3E5EAE5EBE5E5E5E5EBE5E5E3EBE5E5E5E5E5E11AE8E9E5DF:20108000E5E3EBE5E3E5E5EBE5E1E2E2EBE5E2E5E5EBE5E1E2E2EBEAE5E8E9E5E5EBE5E59B:20110000EBE5E1E2EBE5E5EBE5E1E2EBE5E5E5E3EBE5E3E5E8E9E5E5E5E1E0EBE8E9E5E518:20118000E5E5E5E3EBE3E50AE5E5E5E5EAE5E8E2E5E2E1E2E5E2E1E9E5E5E5E31AE3EBE35B:20120000E50AE5E5EBE5E8E9E5E5E5E31AE3EBE3E50AE5E2EBE1E5EBE5E5E2EBE5E8E9E593:20128000E5E5E31AE3EBE3E50AE5E2EBE1E5EBE5E5E2EBE5E8E9E5E5E31AE3EBE3E50AE5EB:20130000EBE5E5E5E5E8E9E5E5E5E30AE5E3EBE5E10AE5EBE8E2E5E2E2E1E2E5E5E2E1E2E9:20138000E5E2E169536900000000E9E2E5E5E5EBE5E3E5EAE5E5E5E7E5E2E7E5E2E5E5EBC4:20140000E5E1CAE5E5E5EAE5EBE5E2E5EBEAE5E30AE20AE2E8E9E5E5E5E31AE5E3E5E3EBBA:20148000E5E3E5EAE8E9E2E5E5E5E5E5E3E5E5E5E1DAE5EBE30AE5E5EBE5E2E5E5E2E5E58D:20150000E5E1CAE2E8E9E2E5E5E5E5E5E3E5E5E5E1DAE5EBE31AE5E5E0E5EBE5E2E5E5E523:20158000E1CAE5E2E8E9E5E5E31AE3EBE3E50AE5EBE5E5E5E5EBE5E8E9E5E5E5E30AE5E338:20160000EBE5E10AE5EBE8E9E1EBE1EBE3E1EBE8E9E5EBE5EBE8000049000000E9E5E5E3EF:201680001AE3EBE3E50AE5EBE5E5E5E5E8E9E5E5E5E30AE5E3EBE5E10AE5EBE800E3EAE2D5:20170000E5E5E2E1E9E5E5E31AE3EBE3E50AE5E5E5E5E5E5E5E5EBE5E5E5E8E9E5E5E5E3C7:201780000AE5E10AE5EBE8E9E5E5E5EBE5E5E5E2E5E5E5E1E0E5E5E1E5E5E5EBEA0020E202:20180000E5E2E1E1E9E5E5E31AE3EBE3E50AE5EBE5E5E5E5E8E9E5E5E5E30AE5E3EBE5E1A5:201880000AE5EBE8E2E5E5E5E2E1E2E5E5E2E10082E9E1EBE1EBE3E1EBE8E9E5E5E31AE396:20190000EBE3E50AE5EBE5E5E5E5E8E9E5E5E5E30AE5E3EBE5E10AE5EBE8E2E5E5E5E2E1AA:20198000E2E5E5E2E1E9E5E3EBE3E5E5E5E1DAE5E2E5E5E5E1CAE3EBE3E5E5E5E1DAE5E2EC:201A0000E5E5E5E1CAEA008200E9E1E1E3EAE0E0E2E5E30AE5E5EBE1E2E1E1E1E1CAE8E383:201A80001AE1E1E1E2E146E5E5E1E5E5E1E10000E9E3EBE3E5E3E5E5E5E1DAE5E2E5E5E507:201B0000E1CAE3EBEA00E9E1E5E503E1EBE5E318E301E1E11AE3E80000E301EAE1E2E5E539:201B8000E5E5E5E3E1E5E2E1E2E5E5E5E5E5E3E1E5E2E1E2E5E5E5E5E5E3E0E5E2E1E2E5D6:201C0000E5E5E5E5E3E1E30AE3E2E1E2E5E5E5E2E1E9E5E5E5E5E5E31AE3EBE3E50AE5E5BC:201C8000E5E5E5E5E5E5E5E5E5E8E2E5E5E5E2E1E2E5E5E5E2E1E2E5E5E5E2E1E1E1E2E5CA:201D0000E3E5E5E5E3E5E5E30AE5E5E2E5E5E31AE2E1E2E5E5E3E5E2E1E9E5E5EBE5EBE8D4:201D8000E2E5E5E5E5E5E2E1E9E5E5E3EBE8E9E5E5E3EBE8E9E5E5E3EBE8E2E5E5E5E5E292:201E0000E5E5E5E1E5E2E1E2E5E5E5E5E5E2E1E2E1E5E5E1E5E1E5E5E1E5E1E5E2E1E2E15C:201E8000E5EAE5E5E3E5EAE5E5E3E5EAE1E30AEAE2E1E2E5E5EAE5E5E3E5EAE2E1E9E2E57B:201F0000E5E5E2E8E8E5E5E3E5E5E5E3E5E5E1EBE5E1EBE5E5EBE2E8E2E5E5E5E5E5E2E122:201F8000E2E5E5E5E3E5E2E1E2E5E5E5E3E5E2E1E2E5E5E3E5E2E1E2E5E5E5E3E5E2E1E9CD:20200000E2E5E5E5E5E5E2E8E8E5EBE5EBE5E5EBE5E5EBE5E2EBE5E5EBE2E8E2E5E5E5E205:20208000E5E5E3E31AE3E2E1E2E5E5E5E2E5E5E3E3DAE3E2E1E2E5E5E5E5E5E5E2E1E2E5A3:20210000E5E5E5E5E5E2E1E9E5E5E308E5E1E5E5E5E30AE10AE5E3E1EAE5E1E5E31AE8E590:20218000E5E5E5E5E5E5E100000000EAE9E5E5E3EBE5E5E3EBE3E50AE5EBEAE3E5E5E0E8FC:20220000E9E2E5E5E5E5E5EAE5E5EBE5E5E5E5EBE30AE5E5E31AE5E5E5E5E5EBE5E5E3E5B2:20228000E5E3E5E5E3EBE3E50AE3E5E3EBE5E3E5E5E5E5E5E2E2E8E2E5E5E5E5E5E0E2E28A:20230000E1E2E5E5E5E2E2E1E2E5E5E5E5E5E31AE5E5E30AE5E5E5E1CAE3EAE3E2E1E9E2FF:20238000E5E5E5E2E5E5E3EBE3E50AE5E5E5EBEAE3E5E5E2E8E9E2E5E5E5E5E31AE3EBE33A:20240000E50AE5E5E5E5E5E5E5E5E3EBE3E50AE3E5E3EBE5EAE3E5E5E3E5E5E3E5E5EBE5C9:20248000E5E5E2E8E2E5E5E5E2E1E2E5E5E5E5E5E0E2E1E9E2E5E5E5E5E5E5E1EBE5E5E5B2:20250000E5E1EBE5E3EBE5E5E3EBE3E50AE5E5E5E5E5E0E5EBEAE3E5E5E0E2E8E9E5E5E5EB:20258000EBE1E5EBE5E5E3E5E5E5EBE5E5E3E5E8E9E5E5E31AE3EBE3E50AE5E3E5E5E3E534:20260000E5E3E5E5E8E9E5E5E5EBE31AE5E5E5E5E7E5E5E5E5E1DAE5E5E2E5EAE5E3E5E8E6:20268000E9E5E5EBE30AE3EBE5EBE31AE5E5E5E7E5E5E5E5E3E7E5E5E5E5E1DAE5E5E2E540:20270000EAE5E3E5E5E8E2E5E5E5E5E5E11AE5E5E5E7E31AE3EAE3E2E1E2E5E5E5E5E5E1BD:202780001AE5E5E5E7E30AE3EAE3E2E1E9E5E5E3E3EBE8E9E5E5E3E3EBE8E9E5E5E3E3EB2D:20280000E8E9E5E5E3E3EBE3E8E301E9E31AE31AE33AE9E2E8E8E22AE8E208E20AE3E2E0B3:20288000E4E408EAE8E808EAE8E808E21210E4E4E8E0E0E8E1E0E0E4E4E8E4E4E208E31A88:20290000E31AE30AE23AE4E0E1E1E22AE308E2202022E22424E8E23AE4E4E1E5E1E5E1E5A8:20298000E22AE208E4E4E21AE8E5E5E9E1E5E5E5E5E5E2E5E3E5E5E5E5E5E1E8E5E3E5EA05:202A0000E1111AE305150AE5E1E5E3031AE5E1E5E9E5E1050AE3EAE5E18AE305151111EA69:202A8000E1E5E315051AE3E5E8E9E1150AE5E30AEBE5E5E1E2E3E2E5E5EAE315E51AE5E140:202B0000E3E8E1858AE1EBE0E33AE0E2E2E5EBE5E5E3E5E5E1E2E8E9E11508E5E30AEBE512:202B8000E5E1E5E2E1E1939AE1E5E3E0E2E18AEAE1E5051AE5E1E5130AE5E0E0E2E2E133CF:202C0000E3151113E3151113E31AE30AE1EBE5E5E0E2E5E1EAE31AE1EBE5E5E0E2EAE1EB7F:202C8000E1EBE5E5E0E5E0E2E1E5EBE5E1E8E9E1E215E11AE1EBE1EAE3E51AEBE3E8E30AE0:202D0000EBE5E5E1E5E5E2E1E3E2E50AE2E10AE18AE5E5E5E0E0E2E1859AE11AE0E0E24A6C:202D8000EBE330333531E53AE3E5E0E2E2E5E1EBEAE1EBE1E50AE1E1EBE1EBE5E1E1EAE1EF:202E0000EAE0E33AE3E5E0E2E2E3E5E2EBE5E1E1E8E9E1E1E20AE3859AE1E50AE1EBE1EA3B:202E8000E30AEBE5E5E1E2E3E2E5E5E5E1E30AE2E0E5E0E2E0E0E0E2EAE0E0E1303AE34583:202F00005AE31AEAE31AE5E1E3E8EBE3E1E5E20AE0E5EBE33530353AE0E2E5EBE5E1E1E8DA:202F8000E9E0E1EBE10308E2E1E308E2E41AE800100000000010E1E1E1E9EBEAE5E9E5E125:20300000E1E5E5E30AE1E1E5E5E30AE1E5E5E1EBE800000000E9E30AE38482831AE30801F8:20308000E2E1E33AE1E33AE1E33AE9E1E1E2E2E8E28AE8E318E314E310E315E8E1E9E2E553:20310000E3E5E3E5E3E5E3E3E5E5E3E3EFE2E8E9E2E5E5E3E5E3E5E3E5E3E5E5E5E3E3EF14:16318000E2E8E9E2E5E5E5E5E5E3E5E3E5E3E5E5E5E3E3EFE2E88A:2033C8000000000000000000000000000000000000000000000000000000000000000000E5:20344800000000000000000000000000000000000000000000000000000000000000000064:1634C80000000000000000000000000000000000000000000000EE:2035200000001F000015000000000000000043000000000000000000000000000000000014:2035A0000010000000000000000000000000000000000000000000000000000000000000FB:0136200000A9:023624000000A4:00000001FF";

	return cb;
}

