#include "stdafx.h"
#include "CppUnitTest.h"
#include "../BigInt/BigInt.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTestEqual)
	{
	public:

		TEST_METHOD(TestMethodPosEqual)
		{
			BigInt b1("100");
			BigInt b2("100");
			Assert::IsTrue(b1 == b2);
		}

		TEST_METHOD(TestMethodNegEqual)
		{
			BigInt b1("-100");
			BigInt b2("-100");
			Assert::IsTrue(b1 == b2);
		}

		TEST_METHOD(TestMethodNotEqual)
		{
			BigInt b1("100");
			BigInt b2("-100");
			Assert::IsFalse(b1 == b2);
		}

	};
	TEST_CLASS(UnitTestSum)
	{
	public:

		TEST_METHOD(TestMethodPosPos)
		{
			BigInt b1("340282366920938463463374607431768211456");
			BigInt b2("147808829414345923316083210206383297601");
			BigInt b3("488091196335284386779457817638151509057");
			Assert::IsTrue(b1 + b2 == b3);
			Assert::IsTrue(b2 + b1 == b3);
		}
		TEST_METHOD(TestMethodPosNeg)
		{
			BigInt b1("170141183460469231731687303715884105728");
			BigInt b2("-49269609804781974438694403402127765867");
			BigInt b3("120871573655687257292992900313756339861");
			Assert::IsTrue(b1 + b2 == b3);
			Assert::IsTrue(b2 + b1 == b3);
		}
		TEST_METHOD(TestMethodPosNegNeg)
		{
			BigInt b1("1606938044258990275541962092341162602522202993782792835301376");
			BigInt b2("-265613988875874769338781322035779626829233452653394495974574961739092490901302182994384699044001");
			BigInt b3("-265613988875874769338781322035779625222295408394404220432612869397929888379099189211591863742625");
			Assert::IsTrue(b1 + b2 == b3);
			Assert::IsTrue(b2 + b1 == b3);
		}
		TEST_METHOD(TestMethodNegNeg)
		{
			BigInt b1("-1267650600228229401496703205376");
			BigInt b2("-129934811447123020117172145698449");
			BigInt b3("-131202462047351249518668848903825");
			Assert::IsTrue(b1 + b2 == b3);
			Assert::IsTrue(b2 + b1 == b3);
		}

	};
	TEST_CLASS(UnitTestSubs)
	{
	public:

		TEST_METHOD(TestMethodPosPos)
		{
			BigInt b1("340282366920938463463374607431768211456");
			BigInt b2("147808829414345923316083210206383297601");
			BigInt b3("192473537506592540147291397225384913855");
			Assert::IsTrue(b1 - b2 == b3);
			Assert::IsTrue(b2 - b1 == -b3);
		}
		TEST_METHOD(TestMethodSelf)
		{
			BigInt b1("340282366920938463463374607431768211456");
			BigInt b2("340282366920938463463374607431768211456");
			BigInt b3("0");
			Assert::IsTrue(b1 - b2 == b3);
			Assert::IsTrue(b2 - b1 == -b3);
		}
		TEST_METHOD(TestMethodPosNeg)
		{
			BigInt b1("170141183460469231731687303715884105728");
			BigInt b2("-49269609804781974438694403402127765867");
			BigInt b3("219410793265251206170381707118011871595");
			Assert::IsTrue(b1 - b2 == b3);
			Assert::IsTrue(b2 - b1 == -b3);
		}
		TEST_METHOD(TestMethodPosNegNeg)
		{
			BigInt b1("1606938044258990275541962092341162602522202993782792835301376");
			BigInt b2("-265613988875874769338781322035779626829233452653394495974574961739092490901302182994384699044001");
			BigInt b3("265613988875874769338781322035779628436171496912384771516537054080255093423505176777177534345377");
			Assert::IsTrue(b1 - b2 == b3);
			Assert::IsTrue(b2 - b1 == -b3);
		}
		TEST_METHOD(TestMethodNegNeg)
		{
			BigInt b1("-1267650600228229401496703205376");
			BigInt b2("-129934811447123020117172145698449");
			BigInt b3("128667160846894790715675442493073");
			Assert::IsTrue(b1 - b2 == b3);
			Assert::IsTrue(b2 - b1 == -b3);
		}

	};
	TEST_CLASS(UnitTestMulti)
	{
	public:

		TEST_METHOD(TestMethodPosPos)
		{
			BigInt b1("100");
			BigInt b2("100");
			BigInt b3("10000");
			Assert::IsTrue(b1 * b2 == b3);
			Assert::IsTrue(b2 * b1 == b3);
		}

		TEST_METHOD(TestMethodPosNeg)
		{
			BigInt b1("-256597312");
			BigInt b2("538374");
			BigInt b3("-138145321250688");
			Assert::IsTrue(b1 * b2 == b3);
			Assert::IsTrue(b2 * b1 == b3);
		}

		TEST_METHOD(TestMethodNegNeg)
		{
			BigInt b1("-873456580075675");
			BigInt b2("-8756756269520732567532963529017014");
			BigInt b3("7648646383731804838227942798367988825310482534450");
			Assert::IsTrue(b1 * b2 == b3);
			Assert::IsTrue(b2 * b1 == b3);
		}

	};

	TEST_CLASS(UnitTestDiv)
	{
	public:

		TEST_METHOD(TestMethodPosPos)
		{
			BigInt b1("100");
			BigInt b2("100");
			BigInt b3("10000");
			Assert::IsTrue(b3 / b2 == b1);
		}

		TEST_METHOD(TestMethodPosNeg)
		{
			BigInt b1("256597312");
			BigInt b2("538374");
			BigInt b3("138145321250688");
			Assert::IsTrue(b3 / b2 == b1);
		}

		TEST_METHOD(TestMethodNegNeg)
		{
			BigInt b1("873456580075675");
			BigInt b2("8756756269520732567532963529017014");
			BigInt b3("7648646383731804838227942798367988825310482534450");
			Assert::IsTrue(b3 / b2 == b1);
		}

	};
}