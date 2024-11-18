#include "pch.h"
#include "CppUnitTest.h"
#include "../11.3/11.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest113
{
	TEST_CLASS(UnitTest113)
	{
	public:

			

		TEST_METHOD(TestSearchBySurname)
		{
			char fname[] = "testfile.txt";

			std::ofstream fout(fname);
			fout << "Smith John 1234567890 1 1 2000\n";
			fout.close();

			std::streambuf* oldCout = std::cout.rdbuf();
			std::ostringstream output;
			std::cout.rdbuf(output.rdbuf());

			searchBySurname(fname, "Smith");

			std::cout.rdbuf(oldCout);
			std::string result = output.str();
			Assert::IsTrue(result.find("Smith") != std::string::npos, L"Запис не знайдено!");

			remove(fname); 
		}

		TEST_METHOD(TestIsValidDate)
		{
			Assert::IsTrue(isValidDate(1, 1, 2000), L"Дата має бути коректною!");
			Assert::IsFalse(isValidDate(31, 2, 2000), L"Дата має бути некоректною!");
			Assert::IsFalse(isValidDate(29, 2, 1900), L"Дата має бути некоректною!");
			Assert::IsTrue(isValidDate(29, 2, 2000), L"Дата має бути коректною!");
		}
	};
}
