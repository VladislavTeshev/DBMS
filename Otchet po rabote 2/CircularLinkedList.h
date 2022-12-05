#pragma once
 
#include <iostream>
#include <sstream>

using namespace std;

/**
* \brief ��������� ����
 */
struct Node
{
private:
	/**
	 * \brief ������ ����
	 */
	int data;
	/**
	 * \brief ��������� �� ��������� ���� � ������
	 */
	Node* next;

	friend class CircularLinkedList; // ��� ����������� ������ ��� ���������� � privite ����� Node
public:
	/**
	 * \brief ���������� �� ���������
	 */
	Node() noexcept;
	/**
	 * \brief ���������� � �����������
	 */
	Node(const int data_) noexcept;
	/**
	 * \brief ����������
	 */
	~Node() noexcept;
};

/**
 * \brief ����� ���
 */
class CircularLinkedList
{
private:
	/**
	* \brief ��������� �� ������ ������
	*/
	Node* head;
	/**
	* \brief �������� ���� � ���
	*/
	Node* delete_head(Node *node);
public:
	/**
	* \brief ���������� �� ���������
	*/
	CircularLinkedList() noexcept;
	/**
	 * \brief ����������
	 */
	~CircularLinkedList() noexcept;
	/**
	* \brief ���������� ���� � ���
	*/
	void add_node(Node* node) noexcept;
	/**
	* \brief �������� ���� � ���
	*/
	void remove() noexcept;
	/**
	* \brief ����� ���� � ���
	*/
	bool find_node(const int data_) const noexcept;
    /**
     * \brief ������ ������
     * \return ������, ���������� ���� ������
     */
	string print_list() const;
};
