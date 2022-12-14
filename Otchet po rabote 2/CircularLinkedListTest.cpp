#include "pch.h"
#include "CppUnitTest.h"
#include "..\Teshev\CircularLinkedList.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CircularLinkedListTest
{
	TEST_CLASS(CircularLinkedListTest)
	{
	public:
		
		TEST_METHOD(First_node_insert)
		{
			// Arrange
			std::string expected = "1,";

			// Act
			CircularLinkedList list;
			std::ostringstream temp_act;
			list.add_node(1);
			temp_act << list.print_list();
			std::string actual = temp_act.str();

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Second_node_insert)
		{
			// Arrange
			std::string expected = "2,1,";

			// Act
			CircularLinkedList list;
			std::ostringstream temp_act;
			list.add_node(1);
			list.add_node(2);
			temp_act << list.print_list();
			std::string actual = temp_act.str();

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Delete_node)
		{
			// Arrange
			std::string expected = "1,";

			// Act
			CircularLinkedList list;
			std::ostringstream temp_act;
			list.add_node(1);
			list.add_node(2);
			list.remove();
			temp_act << list.print_list();
			std::string actual = temp_act.str();

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Success_node_find)
		{
			// Arrange
			std::string expected = "1";

			// Act
			CircularLinkedList list;
			std::ostringstream temp_act;
			list.add_node(1);
			list.add_node(2);
			temp_act << list.find_node(1);
			std::string actual = temp_act.str();

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Unsuccessful_node_find)
		{
			// Arrange
			std::string expected = "0";

			// Act
			CircularLinkedList list;
			std::ostringstream temp_act;
			list.add_node(1);
			list.add_node(2);
			temp_act << list.find_node(3);
			std::string actual = temp_act.str();

			// Assert
			Assert::AreEqual(expected, actual);
		}
	};
}
