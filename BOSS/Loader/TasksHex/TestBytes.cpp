
#include "TestBytes.h"

TestBytes::TestBytes() {}

CodeBytes* TestBytes::getCodeBytes()  {

	CodeBytes* cb = new CodeBytes();

	cb->byte0 = ":020000040002F8:20000000000029F09001828C01087C010400900400FBF0110403070403040404FB040301EA:200080000101FB0304020400EA1EFF302C1401000000047CFF08000000042C8A0000050098:20010000642800071600080C040000000700021F048C0100840C0800002408EC0C040000A5:20018000000428620000060068240400014C000C0C04000000070002EC048C01005B0C08DD:2002000000000C08DC0F0C080400001401055C034C5403490804510804014D0804023E0C53:200280000011080403370804043E0804082F000000182A04000000182F000F0E08040000C0:200300000004240200009C007C20044CA000CC0114044CA01F00001800081C5F002C0000D4:200380002404001C0800140C000C107000000000F80400F00800E80C00E0106000D4000059:20040000CC0400C40800BC0C00B4105000A80000A00400980800900C00881040007C000088:200480007404006C0800640C005C103000500000480400400800380C003010200014019B2C:2005000001A901B701C501D301E11100E80800341200D408002E0C00BC081028060407EAA9:200580008EEE01F2000E0C0400000004048C0100680C040000180110000800041E0400006A:20060000180110000C00041E08000004001864080C000004001C000600100018610405002F:200680000400185A04040C0010FC343C949038343C949038343C949038343C949038343C24:20070000949038343C94903814A80C040000000428F400000600A424040000DE000C0C04F9:200780000000000700027E048C0100ED0C08000096080800007B0808000081080800008FEF:20080000081C0C040000000424BC00002200E42004000000040004040400080804000C0C5A:2008800004001010040014140400181804001C1C000C0C0400000004288C00000500282473:200900000400BE000C0E0804000C0400E40E000428DF090400DB050800EF01F1F50E080001:20098000000004546100000900805000955B0096285700080C040000000B0002285F000212:200A00005C048C0100530C0400041E00300400040008B1085C080245300000300400040058:200A800008A2085208023630000030040004000893083908022730000034040004000884A5:200B0000083902300817303400FC1C0C080000000404F3000002007C0000080C0400000022:200B800004048C0100F30C0038040008470866343400FC080250380064001804000437080F:200C000008000C08040D1A000C0C8E1F000C0C7A1A000C0C9315041210000C0C9A14001060:200C80009D090D00EB01E401DD01EAFF1800080000000460910000070061006008000C1DFB:200D000000080C040000000B00020C2700005D048C0100850C7C08000000041069000004F7:200D800000100C006800080C0400000007000275048C0100640C08000000020149000008DC:200E00000C0400000002013E00000C0E08040004480E0C04000400BC0C0C040004D40C0C25:200E80000400000002011F00000C0E0804000408AB0E0C040004B70C0C0400000002010651:200F000000000C040000041E04000004041E0C000000040CF100000B049B0000C0003E00C0:200F800004000008000C0C0400000006004B048C0100E60C0E000004C900080004C40004A6:20100000000004C30004000000080C08B5000408008600080174040800080400ED0E0E0004:2010800000016E040008049A000004017C08010804950000040172FF040E080000B50004C3:20110000810000016C00047F000001650000040139000004080C0400008C0C6A0C0F04007D:20118000000C0C04D700080404080000FF000F0400041E0400041E0C04000000040147008E:201200000002000419000C0E040000000402370000090408EA0000DE0004011B000E0E0437:201280000000000403200000090408D30000D7000402CC000E0800000004100A000004005E:201300009400900C00080C0400000007000097048C0100050C040028041E04002C041E04A1:2013800000041E53616563FCD41C0018040004460801140914080C0C140100140114043091:20140000140CF00800100604270C010017041000F501FF18000800F4000008E800E400DF7F:20148000D00100FF080014080400B00C0010100400100CF400FB0C08FC1001100801080423:201500001000EE14000014080400300C00101004000F0CC700FB10080C0CE3100110041014:2015800000EF10140008000000040C5A000006002A009408009E00080C040000000700003D:201600002B048C0100530C0E0DDA0D5A020DE80E001C2118CA0070640094748408000000C7:20168000040C23000004001B00440800080C0400000007000024048C01001E0CAC06AC0848:201700000400081E08000000040CFB00000A00B40800AC0000004D000400080C04000000B1:2017800004048C0100F30C0E000004D308000810040400F00008043C000800015FEAC4005A:201800000400041E1E08000000040CBA00000400B200700800080C04000000070000BB04A6:201880008C0100B50C04002000041E080400081E24000E0D050D2E020D110E0800000004C9:201900000C84000004007C00F40800080C0400000007000085048C01007F0C0400A400044F:201980001E080400081E0C0000A2000404680C0604010450040CF801930004042C0CE804A6:201A0000010414040CF8E04400803000B2000C040004080003040091B20100240484EF30ED:201A8000010014040E011C2014001E0C001E1EB4B00800660000000030000C06000100143F:201B0000000CF80147EF00F00038300105FB0000F000063404F500F0D05C001E1A1E080490:201B800000000400011200081E080400000400011200081E080400000400011200081E086E:201C000004000004000112000001081E0C0804000C1E0F0C0804000000040CAA0000080057:201C80000400000804000C0800000F04000000041E04000004041E04000008041E011E086C:201D000000000400540254040106005801040401F8081E0400000720041E080000E000F263:201D80000808040000040C081E08000080F208080000BFEC0808000000E6080804000004B6:201E0000FF0000044C04081E080400000420081E08B40000B40C000C00B40C000C081E0871:201E8000B40009000C040C08000C040C03B400F2F6081E080400FF000C080CFF081E00141C:201F0000040004080707000C800C000C400C00BCBE00BECA0010DB14000804000004080892:201F80001E040000081008041E040000104010041E0400000004041E040000101010041ED7:20200000001C18080400080C0707004D00600C00690018C4000CA600046D1C000800001405:2020800001040400000001081E0800001420040400000001081E08040004000000081E0867:20210000040000040000081E307400003068000000040005000308023C01083C0000EE30A0:20218000241C000C0000001ECCB8C420AC0E0000B40E0808B4C6000402040B00000004004E:202200000E0014040000000C03000C2B0C00040C3700F50C04000C0C04040C001A10100094:20228000001000040C0895000803000808870C01000C04040C0814000804000404040C086A:20230000081E0804000408081E0C0804000800000A0804000408040400010100000C1E00E3:20238000140400000C0C000C53000804080C040500001010140000140804000000040CC65B:2024000000001E0004000008040000082F000C05000C08210C000010100000100004004C85:20248000000800140004000008041E0400000004080C041E001C0C08040008000C4214080E:20250000140C0CE5000C3918180CF100100800140404080C10BB00000004001C00001408E9:2025800004000800040004040C0404CA0C080004000C040C0C04BF000047101000000004D7:20260000401010000014000800000004B43800000D002AA80000AC0000B00000AC000C005B:20268000080C04000053000100140000B004000000B0A801000400B001B0020000B0010C89:202700000C00002200010895001C00FB0000AC0C040000AC000C0000ACA801000400AC015C:20278000AC020000AC040C04000000B0AC00070000AC0C0001010000041E04000000B0AC2C:2028000000070000AC0C0001010000041E08000000ED5B0808000001ED540808000002ED34:202880004D0808000003ED460008001E01032B032F10081010181810FB1010010C0D0C1055:20290000030404010608080102080801010402010101B2B20100B2B20101010101010103A4:20298000F9011302CB040704B423B204F9040102B2B20201010101040904042303230223D4:202A00000104F50401010101FB011000003C040400000004000004EC00E8003C00CC000080:202A8000090C0C0500040405041E040000F2001E8010000C0010000A000405000004000307:202B0000060204000004F000041070001812000000B7F0003C070304E000FF0000D803005C:202B80003C00700304F405B406080506040400BF00000100003C047070006070000000897B:202C000038003C30040C030007030001000403F8FF03040036F08100013100010004040506:202C80000000008C0000008C00000A0006056D00000C040003140006066200000C040906E6:202D00005B055900000C000C08060063003C70F00004000103017200560000029A00F00078:202D80000027B0003C00B407860304003201093E092F7C84000601040004168C140C090448:202E0000101A08030100070013010005040400051E1B083500000807068F075B003C05B6DC:202E80003CBA090809010005040401000449003C07F0F000010131046802050003010A00EF:202F00003D0000C528003C070304182000050016040A000C04070C09080103070C08FA008F:202F8000040200EB010003003C00F0B001070004020A00BB08000C0003090400B2003C0774:20300000F0109004C4000010032100100104FC10B000A8A4ACB4FC1E001E00FBFE4C10001A:20308000003C3C000001043C280000003C18003CE810B0C4C0B401030700010103FB0001D3:203100001EFF01041201080D0110081001010F0F1210FC100802040402B20100011E080000:193180000000000000080C040000040000000C0E08040008000406000ED4:2033D4000000007C001800540068000000F4009C00F400F40000005800AC00940000003049:203454000084006C0000006C009C0000000800E4000000E000A8000000B400F40000006CD8:1634D40000F4000000C00000001C00000098000000D00000007832:20352C000490B50494E50498D9049C0104A0E90C641A03000470000C8400741804A400044D:2035AC00A80004AC0104B0B804B4B804B83404BC0004C00004C40004C80304CC0004D0001B:01362C00009D:02363000400058:00000001FF";
	cb->byte1 = ":020000040002F8:200000000000004000000600000050000000064000FF80001000002000303020FF20003086:200080003020FF2020002000FFFFFF3635C0000010001006FF4000C000000006000000C09E:2001000000000010000080401000C00000001000C0CF00000680400000008034401000C016:2001800000000006000000C00000100020000080401000C00000001000C0CF000006804074:2002000000000180344030201000C0C00000041006041006100006C0001006C0001006C053:200280000000C0001006C0001006C0001006C000C0100600C000C01006008040201000C000:2003000000000006000000C00300C002CD00C2C0C0C0020D00C000C000C0C000C00300C0F1:200380000300C00300C00300C0030000C00300C00200C00200C00200C0020000C00200C0C4:200400000200C00200C00200C0020000C00200C00200C00200C00200C0020000C00200C048:200480000200C00200C00200C0020000C00200C00200C00200C00200C0020000C0C0C0FF0B:20050000C0FFC0FFC0FFC0FFC0FF0000113020FF0000113020FF0000113020FF00C0C0FF81:20058000C0FFC0FF0080401000C00000C0CF00000580D000C0C000CC0000C0D0FFD000C0FE:20060000C000CC0000C0D0FF4000C000C01005804000C0C0C0C00000C000C010050000C0D5:2006800000C010050000804C4C340000000000000000000020202020204040404040606099:2007000060606080808080802A20401000C000000004000000C00000100020FE008040101D:2007800000C000000010FFC0CF00000480400000FF80400000FF80400000FF80400000FFFB:200800008035401000C000000004000000C00200C000C0C0C000C0C0C000C0C0C000C0C04D:20088000C000C0C0C000C0C0C000C0C0C000C0C00080401000C000000004000000C0020002:200900001000FF008040201000000010FF00C00010FF000010FF00C000FFC0FFFF804000AE:20098000C000000004000000C001000010FFC01000FF0080401000C00000C01000FF001085:200A0000FFC0CF00000480D000D0FF40D01000200010FF00FF0010FFD08040D01000200038:200A800010FF00FF0010FFD08040D01000200010FF00FF0010FFD08040D01000200010FFED:200B000000FF100000FF00D0803435354000C000000003000000C000000080401000C00086:200B800000C0CF0000038040D0100000FD00FD00C000FF0010FDD0803440D01000000400B5:200C0000C0C0C0C0C0C000C01000FF00C01000FF00C01000FF00000400C01000FF00001004:200C80000200C000FFC0FFC0FFC0FFFFD0804000C0000000030000000002C00000C000FF83:200D00000080401000C00000C01000FF001002C0CF00000380344000C00000000300000019:200D8000C0060000000080401000C00000001000C0CF000003804000C00000000300008058:200E0000401000C0000000030000804020100000038040100000100080401000000080405C:200E80001000C0000000030000804020100000100080401000000080401000C0000000031C:200F0000000080D00000D0FFD000C000D0FF4000C00000000200000000FF1000000000C082:200F800000C000000080401000C000000000C0CF000002804000C000FFC0C0C000FFC0C032:20100000C0C000FFC0C0C0C000000000FFC0C01000FF001020FFC0C0C000C000FF804000D5:201080000010FF00C0C000FFC0102000FFC0C0C000FFC0102000FFFF0080400000FFC00027:20110000FFC01000FFC000FFC01000FFC0001020FFC0000080401000C00101028040100060:20118000C0C0100002000000C000C0C0FF0080D000D0FFD000D0FF401000C00000000200AE:2012000000000010FF0080401000C0000000020000001000FE1000FFC01000FF0080401071:2012800000C0000000020000001000FE1000FFC01000FE00804000C000000002000000001F:20130000FEC000000080401000C000000010FEC0CF00000280D00000D0FFD00000D0FFD052:2013800000D0FF656C726533331640D01000000200C0C000C00010C10000C0C0C0C0000225:20140000C000FFC0C0C00000022010000000C000FFC0FFD0804000C1C000002110013002A8:2014800001C0C0FF8040D0201000C1C0C0C000C00000000200FF001002C0C0C0C0C0C0C0F8:201500000000FFD08040D0201000C1C0C0C000C00000000200FF00C0100002C0C0C0C000A8:2015800000FF00D0804000C0000000010000000000C0000000FF0080401000C0000000109C:2016000000C0CF000001804000FF00001000FF804000FF0002803333003433334000C0002B:201680000000010000000000C000000080401000C00000001000C0CF00000180340002D0D3:201700001000D0FF4000C000000000000000C00000C00000C00003C0000080401000C00057:2017800000C0CF000000804000C0000300C0C0C0C01000100010C0FFC010002003FF340022:20180000D000D0FFFF4000C00000000000000000FFC000000080401000C000000010FFC00C:20188000CF00000080D000C000D0FFD01000D0FF34004000000000100000804000C00000E7:20190000000000000000FFC000000080401000C000000010FFC0CF00000080D000C000D0FA:20198000FFD01000D0FF40000003C0C0C0000000C0C0C000C000FF0003C0C0C00000FFC015:201A0000C0C000C000FFFF3400384050C04000010010200000001003C00048480001FF8078:201A80000000FFC040E0FF47C000FFC000FFFF3333400003C0C0C0C000C00000C0C0C000FB:201B0000C000FF0003FF35405060705000034000800040FF00FF0080333000FF04FFD01059:201B800000C00010200000D0FFD01000C00010200000D0FFD01000C00010200000D0FFD078:201C0000100010C010200C000000D0FFD0201000D0FF4030201000C0000000FF00000000AB:201C8000C0C000C0C000C0C0000080D000C000D0FFD000C000D0FFD000C000D0FF00FFD058:201D000000C0C0C0000000C00000C0C0C0C0C000FFD0FFD000C00000D0FF400000FF00FF98:201D800080D0100000C0C0D0FF40000010FF8040000010FF8040000010FF80D0100000C087:201E0000C0C000C0C4C0D0FFD0100000C0C0D0FFD01000C000100000C010000000D0FFD0E1:201E8000100000C000000000C000000000C000FFFFD0FFD01000FFC0000000FFD0FF40D0A8:201F0000100000C00000C0000000C00000000010FF0010FF0010FFD080D0100000C0C0D0C4:201F8000FFD000C0000000D0FFD000C0000000D0FFD000C00000D0FFD000C0000000D0FFC6:2020000040D03020100000C0000000FF00FF1000FF0010FF0010FF0010FFD080D000C0C0B6:20208000C0C0C000000000D0FFD000C0C0C0C0C000000000D0FFD01000C000C0C0D0FFD013:202100001000C000C0C0D0FF404000008050C000000000000000C010FF00C0FF0000FF8083:20218000C010C010C0C000FF33333321034000001000001000FE00000000010000C0C00084:202200008040D01000C0C0C000001000000010200000FFC0C0000000C0C010000000C000CF:2022800000C000001000FE00000010002003C0000000C0C0C000D080D0100000C000C0008D:20230000D0FFD01000C000D0FFD0201000C0C00000C0C0000000C0000000000000D0FF40B0:20238000D01000C0C0C01000FE0000000010200000000000D08040D0201000C0000000FD92:2024000000000000C0C000C0C0C01000FE00000010002003C000C0C0C00000C0000000FFFC:20248000C00000D080D000C000D0FFD000C000C00000D0FF40D030201000C00011FF00C0AE:20250000001021000010FF001000FD00000000C01000203000FD0000C0C000D08040D02051:202580001000C00000C000C0C0C000FD00C00000C000C0C0C000FD1000FF00C000000010D2:20260000FF00C00000D0804000C0000000FD000000C00000C00000C00000C000C0101100CD:2026800080401000000000000000C01000C0C100C000C0000000C000000000C00000008099:202700004000000000000002000000FFC000C0C1C0C000C0101100C000C0000000C0000096:202780000000C000000080D000C000C0000000C000C0C10000000000D0FFD000C000C00049:202800000000C000C0C10000000000D0FF4000102000028040001020000280400010200054:202880000280400010200002008000FF400000000000000020505020FF002080300020C0F6:20290000F130308000101080005050802030F23030803030800030303030803030208000E4:20298000FF000000FF20003030383020FF0080203030202030308020003030343034303496:202A00003020FF2080303020FF80C6C040FF06C600C6C0C0C0C0C005C0C5C0FF801520C0F3:202A80000000200000C0C000C0FFC000C0FFC0FF1540C02000003000E00000000020C00074:202B0000003020004000FFC0C0804040C500C00000FFC4C0FFC0C060C450FF00304400C078:202B8000FF00800050FF00FFC000000000C0C0FF60C0C0C0C0FF00804050C480C00000FFB7:202C0000C4C0FFC45030006000600000003000FFFF00441000032F0010001010C050C00079:202C80005000C0CF6000C0CF500000000000FFC000C0C0C00000000000FFC000C0C00000D8:202D0000FF00FFC000C000C0C000C0FFC0FF80437050C3800000FF700000C000FF008300C0:202D800000FFC2C0FF6042C00FC090C0006000000000122210C0100000C0001F00C0C0302F:202E000000FF0000000050C000C0C0C050C0C000FF0000FF50C0001020FE00FFC0FF00FF9A:202E8000FFFF000000C0C0C050C0C0C000FFC0FF0083478040500000C10000C00000FF70DC:202F0000000000FEC1C0FFC0C090C16100100000A0C0207030C0C040C00030700040FF0072:202F8000000000FF000000C0FF0087FEC000C05000C0C0FE00C0C0C00000C0C0FEC0FF0023:2030000087400100FEC00080101120801020FF803320333333331FFF00FF40FFFFC040C000:2030800040FFC0C0000000FFC0C00000FFC0C0FFFF803333333340000000102000FF00407A:20310000FF10140000180000E000000040C030205030FF00004000100010001040FF4000D6:1931800010002030008040100000102030008040201000301020000080D6:2033D4000000001300130013001300000016000D00160016000000180018001800000019DD:20345400001900190000000B000B0000000D000B000000150013000000160016000000178D:1634D40000160000000100000001000000050000000900000007B5:20352C0000333B0033550033A30033000033BA003300000000330000330033130033200061:2035AC00332000330000331A00331A00331200330000330000330000330000330000330068:01362C00009D:02363000160082:00000001FF";
	cb->byte2 = ":020000040002F8:200000000000002D9F70009F70009F750000009554FFBD009011005200908152FF9200D025:20008000C152FF1062809052FF2FFF02029F7CA0A09C8C00FF2D8D9D5C00A000508D009DFA:200100009F8C9DA0009DBD2D8D8D9D5C009DA0009DB0009D00BD2D8D9D00BD022D8D8D9DFF:200180005C00A000508D009D9F8C9D9DA0009DBD2D8D8D9D5C009DA0009DB0009D00BD2D39:200200008D9D00BD022DCD8D8D8D9D9C5C009FA0009FA0009D9D009D9D8C009D9D8C00DD9E:200280005C009D9D8C009D9D8C009D9D8C009D9C9D9C00009D9C9D9C008DBD2DCD8D8D9DD1:200300005C00A000508D009D9F8C9DA08C9DA08C809DA08CC04C9D809DDDC0009D9F8C9D99:200380009F8C9D9F8C9D9F8C9D9F8C009D9F8C9D9F8C9D9F8C9D9F8C9D9F8C009D9F8C9D8D:200400009F8C9D9F8C9D9F8C9D9F8C009D9F8C9D9F8C9D9F8C9D9F8C9D9F8C009D9F8C9D0C:200480009F8C9D9F8C9D9F8C9D9F8C009D9F8C9D9F8C9D9F8C9D9F8C9D9F8C009D9C5CFF5D:200500005CFF5CFF5CFF5CFF5CFF009D9FDDA0FF009D9FDDA0FF009D9FDDA0FF009D5CFFF4:200580005CFF5CFF9DBD2D8D8D9D5C009DB0009D00BD4D8D9D9CA0A09D90808D2F4D8D9D31:200600009CA0A09D90808D2F2D8D9D9C9D9C00BD2D8DA0CD9DDC5C009D9C9D9C00CD009DD4:200680009C9D9C00CDDDBD00000231313131310505050505050505050505050505050505D2:20070000050505050505050500002D8D8D9D5C00A000508D009D9F8C9D9DA0FF9DBD2D8D3F:200780008D9D5C009DA0FF9DB0009D00BD2D8D9DFFBD2D8D9DFFBD2D8D9DFFBD2D8D9DFF61:20080000BD022D8D8D9D5C00A000508D009D9F8C9D9D9C809D9D9C809D9D9C809D9D9C803C:200880009D9D9C809D9D9C809D9D9C809D9DDCC09DBD2D8D8D9D5C00A000508D009D9F8CA1:200900009D9DFF9DBD2DCD8D8D009D9DFF009D9D8CFF009D9DFF00DD5CFF5CFFFFBD2D8DF0:200980009D5C00A000508D009D9F8C9DA0FF9DA08CFF9DBD2D8D8D9D5C009DA08CFF9DA076:200A0000FF9DB0009D00BD4D8D8D2F2D4DCD8DDD9D8DFF8DFF8DA0FF8DBD2D4DCD8DDD9D70:200A80008DFF8DFF8DA0FF8DBD2D4DCD8DDD9D8DFF8DFF8DA0FF8DBD2D4DCD8DDD9D8DFF12:200B00008DFFA0CD8DFFDD8DBD0202022D8D9D5C00A000508D009D9F8C9DBD2D8D8D9D5C91:200B8000009DB0009D00BD2D4D8D8D8DFF8DFFCDDD5CFF8DA0FF8DBD022D4D8D8D9D008DC7:200C00009DDCCD9DDCCD009DDD8CFF009DDD8CFF009DDD8CFF009D008D9DDD8CFF8D9D8D53:200C80000000DD5CFF5CFF5CFF5CFFFF8DBD2D8D9D5C00A000508D009D009D9F8C9D8CFF05:200D00009DBD2D8D8D9D5C009DA08CFF9DA0009DB0009D00BD022D8D9D5C00A000508D005B:200D80009D9F8C9D009DBD2D8D8D9D5C009DA0009DB0009D00BD2D8D9D5C00A0008D9DBD36:200E00002D8D8D9D5C00A0008D9DBD2D8D8D8D9D00BD2D8D8D9DA000BD2D8D8D9D00BD2DCE:200E80008D8D9D5C00A0008D9DBD2D8D8D8D9D9D00BD2D8D8D9D00BD2D8D8D9D5C00A0006C:200F00008D9DBD4D8D9D8D2F4D8D9D8C8D2F2D8D9D5C00A000508D008DFFA09D009D009DC5:200F80008C9DA08C9DBD2D8D8D9D5C009D009DB0009D00BD2D8D9D9CFF908D9D9CFF9D9C9E:20100000809D9CFF9D9C809DA08C009DFF908D9D9DFF9D9DA0FF9D8D9D9D9C5CFFBD2D8DF9:201080009DA0FF8DA08D9DFF9DA08D8CFF9D8C8D9DFF9DA08D8CFFFF9DBD2D8D9DFF9D9CDA:20110000FF9DA08CFF9D9CFF9DA08CFF9D9D9CA0FF9DA08CBD2D8D8D9DA08000BD2D8D8D05:201180009D8D9DA000508D009D9D9C80FF8DBD4D8D8D2F4D8D8D2F2D8D8D9D5C00A0005010:201200008D009D9DFF9DBD2D8D8D9D5C00A000508D009D8DFFA09DFF9D9D8CFF9DBD2D8DB3:201280008D9D5C00A000508D009D8DFFA09DFF9D9D8CFF9DBD2D8D9D5C00A000508D009DFA:20130000FF9D9F8C9DBD2D8D8D9D5C009DA0FF9DB0009D00BD4D8D8F8D2F4D8D9F8D2F4DE2:201380008D8D2F725F76000202022D4D8D8D9D008DA08D009D9D9DD09D40C19D8C8D9D0034:201400009D50FF9DDCCD009D009D409D0000DD5CFF5CFF8DBD2D8D9F9C5C009FA09FA000D7:201480009FA080FFBD2D4D8D8D8D9F8DA08D9D9D5C009D0050FF9D9D009D8C8D9D8C8D9D92:201500009D5CFF8DBD2D4D8D8D8D9F8DA08D9D9D5C009D0050FF9D9D809D009D8C8D9D9D46:201580005CFF9D8DBD2D8D9D5C00A000508D009D009D9F8C9DFF9DBD2D8D8D9D5C009DA001:20160000009DB0009D00BD2DA0FFA000A0A0FFBD2D9FFF9F00BD0202020202022D8D9D5CD5:2016800000A000508D009D009D9F8C9DBD2D8D8D9D5C009DA0009DB0009D00BD02A0004DFB:201700008D8D8D2F2D8D9D5C00A000508D009D9F8C9D9F8C9D9C009D8C9DBD2D8D8D9D5C37:20178000009DB0009D00BD2D8D9D9C008D9D9C8C8D9D9DD1819D9C2F9D9D9CA000FF020065:201800004D8D8D2F2F2D8D9D5C00A000508D009DFF9D9F8C9DBD2D8D8D9D5C009DA0FF9DFC:20188000B0009D00BD4D8D9F9C8D2F4D8D8D8D2F020F2DA000A000A0A000BD2D8D9D5C001C:20190000A000508D009DFF9D9F8C9DBD2D8D8D9D5C009DA0FF9DB0009D00BD4D8D9F9C8DC7:201980002F4D8D8D8D2F2D8DA000A08D9D9F50009D8C8D9F9D50FFA000A08D9D9F50FF9DAC:201A00008C8D9F9D50FFFF0210012DA0D5A000808580915200919100D584A0A05CA0FFBDF3:201A800014002FA0A08F2FC09F8C2F9F8C2F2F02022DA000A08DA08D9F9D50009D8C8D9F56:201B00009D50FFA000FF0C2DB09F9FA0A0009750BD54A02F56FFA0BD0202502F002F4D8DCE:201B80008D9D9D9CA0818C8D2F4D8D8D9D9D9CA0C18C8D2F4D8D8D9D9D9CA0218C8D2F4D00:201C00008D8D9D9D91A011A000A08D2F4D8D8D8D8D2F2D8D8D8D8D9D5C00A0FF508D009D0F:201C80009D809D9D809D9D809D8DBD4D8D9D9C8D2F4D8D9D9C8D2F4D8D9D9C8D2FA02F4D43:201D00008DA08D9D9C808C9D5C009D9C0C8D9D5CFF8D2F4D8D9DA08C8D2F2D8D9DFF9DFFF4:201D8000BD4D8D8D9D9D808D2F2D8D9DA0FFBD2D8D9DA0FFBD2D8D9DA0FFBD4D8D8D9D9DEF:201E00000C809D9DA0808D2F4D8D8D9D9D808D2F4DCD8D9DDD9CC18C9DDD9C818C8D2F4D0D:201E8000CD8D009D9CC08C009D9C808C00DD5CFFFF8D2F4D8D8DFF9D9CC08CFF8D2F2D4D0B:201F00008D8D9D8D908C9D9CC08C9D9CC08C9DDDFF9DDDFF9D9DFF8DBD4DCD8D9DDD808DB4:201F80002F4D8D9D9C808C8D2F4D8D9D9C808C8D2F4D8D9DA08C8D2F4D8D9D9C808C8D2F22:202000002D4DCD8D8D8D9D8D908C9DFF9DFF9D9DFF9DDDFF9D8DFF9D9DFF8DBD4D8D9D9CE3:202080000C8D9D5CA000A08D2F4D8D9D9C0C8D9D5CA000A08D2F4D8D8D9D9DDC808D2F4D0B:202100008D8D9D9D9CC08D2F2D9F9450BD9FA09C849C500055009CA02F009C2F9450FFBD70:202180009F9F819F9180812F02020202002D8D9DA0008D9DA0FF508D009D0000A09D9C8C79:20220000BD2D4D8D8D9D9C8D009D9D008D9D9D9D0050FF9D9C5C009D9D809D9D008D9DA067:202280008C9DA08C9DA0FF508D00A09DA0009DA08C9D9D809D8C8DBD4D8D8D9D9D90808CC0:202300008D2F4D8D8D9D4C8D2F4D8D8D8D9D9C5C009D9C5C009D9D905C00A000A08D2F2D88:202380004D8D8D9D8C8D9DA0FF508D009D9D9D0000A08D9D8DBD2D4D8D8D8D9D5C00A0FF63:20240000508D009D9D809D9D809D9CA0FF508D00A09DA0009D00A08D9DA08C9DA08C9DFFE1:202480009D8C9D8DBD4D8D9D9C8D2F4D8D9D9D9C90408D2F2D4D8D8D8D8D9D9DA0FF8D9D70:202500009D9DA0009DA0FF8D9DA0FF508D009D9D9D909D809DFF00A09D9C8C8DBD2D4DCDE9:202580008D8DDD5C009D9D9C408D9DFF8DDD5C009D9D9C408D9DFFA09DFF8D9DA08C9D9DD8:20260000FF8D9DA08C8DBD2D8D9D5C00A0FF508D009DA08C9DA08C9DA08C9D9D9CA0809DFE:20268000BD2D8D8D9D005000A0009D9D9C9D819D9D909C805C009D9C808C009DA08CA0BD08:202700002D8D9D005000A0009D0050FF9D9D9C908D9D9D9CA0809D9D909C805C009D9C80A2:202780008C009DA08C9DBD4D8D9D9D9C905C009D9D9C905C00A000A08D2F4D8D9D9D9C90F0:202800005C009D9D9C905C00A000A08D2F2DCDDDA0A000BD2DCDDDA0A000BD2DCDDDA0A0DF:2028800000BD2DCDDDA0A000A0BD522F2D1100100052002D42B1A052FFBD92BD1200D24F96:202900008C9180BD00B1A0BD00B1A0BD524F83D1C0BDD1C0BDA0D1C0D1C0BDD1C052BD1151:20298000FF100010FF520091C0A04052FF72BD92D1C04292D1C0BD520091C0A040A040A0CE:202A00004052FF92BDD1C052FFBD9F9C2D2F9F9F8C9F9C4C80A0809F809F9C2FBD9FA09199:202A80000050A00052909000822F925CA0FF812F9F2D91B08100A000905E00538180A0A036:202B000000A093529283FFA080BD2DB09F009C5C00FF9F9C2F84CC4C9F9CFF55959F00946F:202B80002FA0BD5695FFA0FF435C0085804C80FF85958C85942F85BD2DB09FBD9C5C00FF51:202C00009F9C2F9F45A055A000A096C0838055FFFF559F93009FB090C10083838C814C5CA3:202C8000A05696B0A05595B0A056005500A0FF9395808C83A0005500A0FF9693808C00A0B4:202D0000FFA0FF96938095808CA086FF942FBD2DB0479FA000A0FFA000589C00FFA0BD5CD8:202D800000FF9F9C2F959F88B0CC4C940046560056009F9F9185828C519C00B000864C9C53:202E000000FF53898085A094008985898C4385A0FF00A0FFB09400A0A0FFA0FF942FA0FFF1:202E80002FFF4650008985898C408C8585FF942FA0BD2DA0B04800589F00189C00A0FFA0A7:202F0000005C00FF9F9C2F84CC4C9F9F9CE0500080859001474A824C800088885344FF54D7:202F8000900050FF005000962FA0BDFF895A8347004580FF5495848500874480FF962FA0CF:20300000BD2D04A0FFB0A0BD84B0A0BD518CFFBD020002020202002FA02F2DFFFF9F2D9C51:20308000A02F9F9C5C00A02F9F9C5C002F9F9C2FFFBD020202022D100052C05210FF52BD48:203100002F01815200815200A052002DA0A04202A053FFBD12A0128012C012C0BD2F2D8DF9:19318000A09DA0A000BD2D8D8D9D9DA0A000BD2D8D8D8D9D9D9DA000BD76:2033D4000000000200020002000200000002000200020002000000020002000200000002C1:20345400000200020000000200020000000200020000000200020000000200020000000242:1634D40000020000000200000002000000020000000200000002D6:20352C0000021200029A0002F600020000026C00020000000002000002000202000200005B:2035AC000200000200000202000202000200000200000200000200000200000200000200E5:01362C00009D:02363000020096:00000001FF";
	cb->byte3 = ":020000040002F8:2000000010EBEBE9E5E31BE5E31BE5E30AEAEBE4E31AE8EAE4E31AE24AE4E4E25AE20AE410:20008000E4E21AE21210E4E31AE1FF0000E5E303011512EAFFE9E5E5E31AE3EBE3E50AE5AA:20010000E5E5E5E3EBE5E8E9E5E5E5E30AE5E3EBE5E10AE5EBE8E9E5E5EBE800E9E5E5E5B7:20018000E31AE3EBE3E50AE5E5E5E5E5E3EBE5E8E9E5E5E5E30AE5E3EBE5E10AE5EBE8E905:20020000E5E5EBE800E9E5E5E5E5E5E5E31AE5E3EBE5E3EBE5E5EBE5E5E2EBE5E5E2EBE5CF:20028000E30AE5E5E2EBE5E5E2EBE5E5E2EBE5E5E5E5EBEAE5E5E5E5EBE5E8E9E5E5E5E57A:20030000E31AE3EBE3E50AE5E5E5E5E1E0E5E1E2E5E5E1E0E3E0E5E5E5E5E5EAE5E5E5E5FE:20038000E5E5E5E5E5E5E5E5E5E5E5EAE5E5E5E5E5E5E5E5E5E5E5E5E5E5E5EAE5E5E5E5B3:20040000E5E5E5E5E5E5E5E5E5E5E5EAE5E5E5E5E5E5E5E5E5E5E5E5E5E5E5EAE5E5E5E532:20048000E5E5E5E5E5E5E5E5E5E5E5EAE5E5E5E5E5E5E5E5E5E5E5E5E5E5E5EAE5E5E20A90:20050000E20AE20AE20AE20AE20AEAE5E5E5E3EBEAE5E5E5E3EBEAE5E5E5E3EBEAE5E20A4F:20058000E20AE20AE5E8E9E5E5E5E30AE5E10AE5EBE8E2E5E5E5E3E1E5E5E5E2E1E2E5E536:20060000E5E3E1E5E5E5E2E1E9E5E5E5E5E5EBE8E9E5E3E5E5E5E30AE5E5E5E5EBE5EAE50A:20068000E5E5E5EBE5E5E8484800484848484849494949494949494949494949494949493D:2007000049494949494949494848E9E5E5E5E31AE3EBE3E50AE5E5E5E5E5E3EBE5E8E9E5EA:20078000E5E5E30AE5E3EBE5E10AE5EBE8E9E5E5EBE8E9E5E5EBE8E9E5E5EBE8E9E5E5EB37:20080000E800E9E5E5E5E31AE3EBE3E50AE5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5BC:20088000E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E8E9E5E5E5E31AE3EBE3E50AE5E5E557:20090000E5E5EBE5E8E9E5E5E5EAE5E5EBEAE5E5E2EBEAE5E5EBEAE5E30AE20AEAE8E9E5B6:20098000E5E31AE3EBE3E50AE5E5E5E5E3EBE5E3E2EBE5E8E9E5E5E5E30AE5E3E2EBE5E32F:200A0000EBE5E10AE5EBE8E2E5E2E1E9E2E5E5E5E5E2EBE2EBE2E3EBE2E8E9E2E5E5E5E507:200A8000E2EBE2EBE2E3EBE2E8E9E2E5E5E5E5E2EBE2EBE2E3EBE2E8E9E2E5E5E5E5E2EBA3:200B0000E2EBE3E5E2EBE5E2E8000000E9E5E5E31AE3EBE3E50AE5E5E5E5E8E9E5E5E5E37D:200B80000AE5E10AE5EBE8E9E2E5E5E2EBE2EBE5E5E30AE2E3EBE2E800E9E2E5E5E5EBE519:200C0000E5E5E5E5E5E5EAE5E5E2EBEAE5E5E2EBEAE5E5E2EBEAE5EBE5E5E5E2EBE5E5E211:200C8000EBEAE5E30AE20AE20AE20AEAE2E8E9E5E5E31AE3EBE3E50AE5EBE5E5E5E5E2EBB4:200D0000E5E8E9E5E5E5E30AE5E3E2EBE5E3EBE5E10AE5EBE800E9E5E5E31AE3EBE3E50A61:200D8000E5E5E5E5EBE5E8E9E5E5E5E30AE5E3EBE5E10AE5EBE8E9E5E5E31AE3EBE5E5E817:200E0000E9E5E5E5E31AE3EBE5E5E8E9E5E5E5E5EBE8E9E5E5E5E3EBE8E9E5E5E5EBE8E9CB:200E8000E5E5E5E31AE3EBE5E5E8E9E5E5E5E5E5EBE8E9E5E5E5EBE8E9E5E5E5E31AE3EB23:200F0000E5E5E8E2E5E5E2E1E2E5E5E2E2E1E9E5E5E31AE3EBE3E50AE2EBE1E5EBE5EBE5DC:200F8000E5E5E3E5E5E8E9E5E5E5E30AE5EBE5E10AE5EBE8E9E5E5E5EBE5E5E5E5EBE5E549:20100000E5E5E5EBE5E5E5E5E3E5EAE5EBE5E5E5E5EBE5E5E3EBE5E5E5E5E5E11AE8E9E5DF:20108000E5E3EBE5E3E5E5EBE5E1E2E2EBE5E2E5E5EBE5E1E2E2EBEAE5E8E9E5E5EBE5E59B:20110000EBE5E1E2EBE5E5EBE5E1E2EBE5E5E5E3EBE5E3E5E8E9E5E5E5E1E0EBE8E9E5E518:20118000E5E5E5E3EBE3E50AE5E5E5E5EAE5E8E2E5E2E1E2E5E2E1E9E5E5E5E31AE3EBE35B:20120000E50AE5E5EBE5E8E9E5E5E5E31AE3EBE3E50AE5E2EBE1E5EBE5E5E2EBE5E8E9E593:20128000E5E5E31AE3EBE3E50AE5E2EBE1E5EBE5E5E2EBE5E8E9E5E5E31AE3EBE3E50AE5EB:20130000EBE5E5E5E5E8E9E5E5E5E30AE5E3EBE5E10AE5EBE8E2E5E2E2E1E2E5E5E2E1E2E9:20138000E5E2E169536900000000E9E2E5E5E5EBE5E3E5EAE5E5E5E7E5E2E7E5E2E5E5EBC4:20140000E5E1CAE5E5E5EAE5EBE5E2E5EBEAE5E30AE20AE2E8E9E5E5E5E31AE5E3E5E3EBBA:20148000E5E3E5EAE8E9E2E5E5E5E5E5E3E5E5E5E1DAE5EBE30AE5E5EBE5E2E5E5E2E5E58D:20150000E5E1CAE2E8E9E2E5E5E5E5E5E3E5E5E5E1DAE5EBE31AE5E5E0E5EBE5E2E5E5E523:20158000E1CAE5E2E8E9E5E5E31AE3EBE3E50AE5EBE5E5E5E5EBE5E8E9E5E5E5E30AE5E338:20160000EBE5E10AE5EBE8E9E1EBE1EBE3E1EBE8E9E5EBE5EBE8000049000000E9E5E5E3EF:201680001AE3EBE3E50AE5EBE5E5E5E5E8E9E5E5E5E30AE5E3EBE5E10AE5EBE800E3EAE2D5:20170000E5E5E2E1E9E5E5E31AE3EBE3E50AE5E5E5E5E5E5E5E5EBE5E5E5E8E9E5E5E5E3C7:201780000AE5E10AE5EBE8E9E5E5E5EBE5E5E5E2E5E5E5E1E0E5E5E1E5E5E5E3EBEA002001:20180000E2E5E2E1E1E9E5E5E31AE3EBE3E50AE5EBE5E5E5E5E8E9E5E5E5E30AE5E3EBE5A4:20188000E10AE5EBE8E2E5E5E5E2E1E2E5E5E2E10082E9E1EBE1EBE3E1EBE8E9E5E5E31A98:20190000E3EBE3E50AE5EBE5E5E5E5E8E9E5E5E5E30AE5E3EBE5E10AE5EBE8E2E5E5E5E2A8:20198000E1E2E5E5E2E1E9E5E3EBE3E5E5E5E1DAE5E2E5E5E5E1CAE3EBE3E5E5E5E1DAE5ED:201A0000E2E5E5E5E1CAEA008200E9E1E1E3EAE0E0E2E5E30AE5E5EBE1E2E1E1E1E1CAE884:201A8000E31AE1E1E1E2E146E5E5E1E5E5E1E10000E9E3EBE3E5E3E5E5E5E1DAE5E2E5E509:201B0000E5E1CAE3EBEA00E9E1E5E503E1EBE5E318E301E1E11AE3E80000E301EAE1E2E539:201B8000E5E5E5E5E3E1E5E2E1E2E5E5E5E5E5E3E1E5E2E1E2E5E5E5E5E5E3E0E5E2E1E2D6:201C0000E5E5E5E5E5E3E1E30AE3E2E1E2E5E5E5E2E1E9E5E5E5E5E5E31AE3EBE3E50AE5BC:201C8000E5E5E5E5E5E5E5E5E5E5E8E2E5E5E5E2E1E2E5E5E5E2E1E2E5E5E5E2E1E1E1E2CA:201D0000E5E3E5E5E5E3E5E5E30AE5E5E2E5E5E31AE2E1E2E5E5E3E5E2E1E9E5E5EBE5EBD7:201D8000E8E2E5E5E5E5E5E2E1E9E5E5E3EBE8E9E5E5E3EBE8E9E5E5E3EBE8E2E5E5E5E58C:201E0000E2E5E5E5E1E5E2E1E2E5E5E5E5E5E2E1E2E1E5E5E1E5E1E5E5E1E5E1E5E2E1E25B:201E8000E1E5EAE5E5E3E5EAE5E5E3E5EAE1E30AEAE2E1E2E5E5EAE5E5E3E5EAE2E1E9E27F:201F0000E5E5E5E2E8E8E5E5E3E5E5E5E3E5E5E1EBE5E1EBE5E5EBE2E8E2E5E5E5E5E5E21E:201F8000E1E2E5E5E5E3E5E2E1E2E5E5E5E3E5E2E1E2E5E5E3E5E2E1E2E5E5E5E3E5E2E1D5:20200000E9E2E5E5E5E5E5E2E8E8E5EBE5EBE5E5EBE5E5EBE5E2EBE5E5EBE2E8E2E5E5E5FE:20208000E2E5E5E3E31AE3E2E1E2E5E5E5E2E5E5E3E3DAE3E2E1E2E5E5E5E5E5E5E2E1E2A6:20210000E5E5E5E5E5E5E2E1E9E5E5E308E5E1E5E5E5E30AE10AE5E3E1EAE5E1E5E31AE890:20218000E5E5E5E5E5E5E5E100000000EAE9E5E5E3EBE5E5E3EBE3E50AE5EBEAE3E5E5E0FF:20220000E8E9E2E5E5E5E5E5EAE5E5EBE5E5E5E5EBE30AE5E5E31AE5E5E5E5E5EBE5E5E3AF:20228000E5E5E3E5E5E3EBE3E50AE3E5E3EBE5E3E5E5E5E5E5E2E2E8E2E5E5E5E5E5E0E287:20230000E2E1E2E5E5E5E2E2E1E2E5E5E5E5E5E31AE5E5E30AE5E5E5E1CAE3EAE3E2E1E9FF:20238000E2E5E5E5E2E5E5E3EBE3E50AE5E5E5EBEAE3E5E5E2E8E9E2E5E5E5E5E31AE3EB3B:20240000E3E50AE5E5E5E5E5E5E5E5E3EBE3E50AE3E5E3EBE5EAE3E5E5E3E5E5E3E5E5EBCB:20248000E5E5E5E2E8E2E5E5E5E2E1E2E5E5E5E5E5E0E2E1E9E2E5E5E5E5E5E5E1EBE5E5B2:20250000E5E5E1EBE5E3EBE5E5E3EBE3E50AE5E5E5E5E5E0E5EBEAE3E5E5E0E2E8E9E2E5EE:20258000E5E5E5E31AE5E5E5E0E5E5EBE5E5E31AE5E5E5E0E5E5EBE1E5EBE5E5E3E5E5E533:20260000EBE5E5E3E5E2E8E9E5E5E31AE3EBE3E50AE5E3E5E5E3E5E5E3E5E5E5E5E3E7E5BE:20268000E8E9E5E5E5EBE30AE3EAE5E5E5E5E7E5E5E5E5E2E1DAE5E5E2E5EAE5E3E5E3E876:20270000E9E5E5EBE30AE3EBE5EBE31AE5E5E5E7E5E5E5E5E3E7E5E5E5E5E2E1DAE5E5E2C2:20278000E5EAE5E3E5E5E8E2E5E5E5E5E5E11AE5E5E5E7E31AE3EAE3E2E1E2E5E5E5E5E539:20280000E11AE5E5E5E7E30AE3EAE3E2E1E9E5E5E3E3EBE8E9E5E5E3E3EBE8E9E5E5E3E3B6:20288000EBE8E9E5E5E3E3EBE3E8E301E9E31AE31AE33AE9E2E8E8E22AE8E208E20AE3E228:20290000E0E4E408EAE8E808EAE8E808E21210E4E4E8E0E0E8E1E0E0E4E4E8E4E4E208E341:202980001AE31AE30AE23AE4E0E1E1E22AE308E2202022E22424E8E23AE4E4E1E5E1E5E1F3:202A0000E5E22AE208E4E4E21AE8E5E5E9E1E5E5E5E5E5E2E5E3E5E5E5E5E5E1E8E5E3E589:202A8000EAE1111AE305150AE5E1E5E3031AE5E1E5E9E5E1050AE3EAE5E18AE305151111E9:202B0000EAE1E5E315051AE3E5E8E9E1150AE5E30AEBE5E5E1E2E3E2E5E5EAE315E51AE5B6:202B8000E1E3E8E1858AE1EBE0E33AE0E2E2E5EBE5E5E3E5E5E1E2E8E9E11508E5E30AEB96:202C0000E5E5E1E5E2E1E1939AE1E5E3E0E2E18AEAE1E5051AE5E1E5130AE5E0E0E2E2E19C:202C800033E3151113E3151113E31AE30AE1EBE5E5E0E2E5E1EAE31AE1EBE5E5E0E2EAE1B7:202D0000EBE1EBE5E5E0E5E0E2E1E5EBE5E1E8E9E1E215E11AE1EBE1EAE3E51AEBE3E8E37E:202D80000AEBE5E5E1E5E5E2E1E3E2E50AE2E10AE18AE5E5E5E0E0E2E1859AE11AE0E0E22C:202E00004AEBE330333531E53AE3E5E0E2E2E5E1EBEAE1EBE1E50AE1E1EBE1EBE5E1E1EA05:202E8000E1EAE0E33AE3E5E0E2E2E3E5E2EBE5E1E1E8E9E1E1E20AE3859AE1E50AE1EBE1C4:202F0000EAE30AEBE5E5E1E2E3E2E5E5E5E1E30AE2E0E5E0E2E0E0E0E2EAE0E0E1303AE35D:202F8000455AE31AEAE31AE5E1E3E8EBE3E1E5E20AE0E5EBE33530353AE0E2E5EBE5E1E1FD:20300000E8E9E0E1EBE10308E2E1E308E2E41AE800100000000010E1E1E1E9EBEAE5E9E59D:20308000E1E1E5E5E30AE1E1E5E5E30AE1E5E5E1EBE800000000E9E30AE38482831AE30898:2031000001E2E1E33AE1E33AE1E33AE9E1E1E2E2E8E28AE8E318E314E310E315E8E1E9E5B3:19318000E3E5E3E3EFE8E9E5E5E5E5E3E3EFE8E9E5E5E5E5E5E5E3EFE8B6:2033D4000000000000000000000000000000000000000000000000000000000000000000D9:20345400000000000000000000000000000000000000000000000000000000000000000058:1634D40000000000000000000000000000000000000000000000E2:20352C0000001F000015000000000000000043000000000000000000000000000000000008:2035AC000010000000000000000000000000000000000000000000000000000000000000EF:01362C00009D:02363000000098:00000001FF";

	return cb;
}

