// ConsoleApplication3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

struct Node{
	int value;
	Node* next;
	Node(int v) :value(v), next(nullptr) {}
	
};

class NodeListGenerator 
{
	public:
		Node* Generator(const vector<int>& arr)
		{	
			int num = arr.size();
			if (num == 0) {
				return nullptr;
			}

			Node* HeadNode = new Node(arr[0]);
			Node* currentNode = HeadNode;

		
		
			for (int i = 1; i < num; i++) {
			
				currentNode->next = new Node(arr[i]);
				currentNode = currentNode->next;
			}
			return HeadNode;
		}

		void ShowNodeList(Node* head) 
		{	
			if (head == nullptr) {
				cout << "空指针" << endl;
				return;
			}

			Node* curNode = head;
		
			do
			{
				cout << curNode->value << "->";
				curNode = curNode->next;
			} while (curNode != nullptr);
		}

		int GetListLengh(Node* head) 
		{
			int lengh = 0;
			Node* curNode = head;
			do
			{
				lengh++;
				curNode = curNode->next;
			} while (curNode != nullptr);

			return lengh;
		}

		Node* ReverseNodeList(Node* head) 
		{
			Node* s = nullptr;
			Node* f = head;
			
			while(f != nullptr)
			{
				
				Node* temp = f->next;
				f->next = s;
				s = f;
				f = temp;
				
			}
			return s;
		}

		Node* IsPalindromeNodeList(Node* head)
		{	
			
			Node* s = head;
			Node* f = head;

			while (f->next != nullptr) {
				s = s->next;
				f = f->next->next != nullptr ? f->next->next : f->next;
			}

			Node* mid = s;

			Node* end = f;

			f = ReverseNodeList(s);
			s = head;

			while (s && f ) 
			{
				if (s->value != f->value) 
				{
					mid = nullptr;
				}
				s = s->next;
				f = f->next;
			}

			ReverseNodeList(end);
			
			return mid;
		}



};

int main()
{
   
	NodeListGenerator gnt = NodeListGenerator();
	Node* node = gnt.Generator({ 1,2,3,4,5,5,4,3,2,1});
	gnt.ShowNodeList(node);
	std::cout << "" << endl;
	/*node = gnt.ReverseNodeList(node);*/

	node = gnt.IsPalindromeNodeList(node);

	gnt.ShowNodeList(node);

}

