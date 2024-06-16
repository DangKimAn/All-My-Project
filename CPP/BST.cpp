#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

class Node {
public:
	int value;
	Node* pRight;
	Node* pLeft;
};

class Tree {
public:
	Node* root = new Node;
};

Node* CreatNode(int value)
{
	Node* node = new Node;
	node->value = value;
	node->pLeft = NULL;
	node->pRight = NULL;
	return node;
}

Tree* CreatTree()
{
	Tree* tree = new Tree;
	tree->root = NULL;
	return tree;
}

void Menu()
{
	cout << setw(4) << left << "1." << "Tao mot cay tu dong theo so co san" << endl;
	cout << setw(4) << left << "2." << "Tim kiem so ban muon" << endl;
	cout << setw(4) << left << "3." << "Them node moi" << endl;
	cout << setw(4) << left << "4." << "Xoa node" << endl;
	cout << setw(4) << left << "5." << "Chieu cao" << endl;
	cout << setw(4) << left << "6." << "Tim kich co cua node" << endl;
	cout << setw(4) << left << "0." << "Thoat chuong trinh" << endl;

}

Tree* CreatTreeAuto()
{
	Tree* tree = new Tree;
	tree = CreatTree();
	ifstream Input;
	Input.open("INPUT.txt", ios::in);
	bool breakwhile;
	while (Input.eof() != true)
	{
		int value;
		Input >> value;
		Node* pPush = new Node;
		pPush = CreatNode(value);
		if (tree->root == NULL)
			tree->root = pPush;
		else
		{
			Node* pChild = new Node;
			pChild = tree->root;
			breakwhile = false;
			do
			{
				if (pPush->value > pChild->value)
				{
					if (pChild->pRight != NULL)
						pChild = pChild->pRight;
					else {
						pChild->pRight = pPush;
						breakwhile = true;
					}
				}
				else if (pPush->value < pChild->value)
				{
					if (pChild->pLeft != NULL)
						pChild = pChild->pLeft;
					else {
						pChild->pLeft = pPush;
						breakwhile = true;
					}
				}
				else {
					breakwhile = true;
				}
			} while (breakwhile == false);
		}
	}
	system("cls");
	cout << "Done" << "\n";
	system("pause");
	return tree;
}

void SearchValue(Tree *tree)
{
	system("cls");
	int value;
	cout << "Nhap so ban muon tim kiem: ";
	cin >> value;

	Node* pCurrent = new Node;
	pCurrent = tree->root;
	while (pCurrent)
	{
		if (pCurrent->value == value)
		{
			cout << "Co\n";
			system("pause");
			return;
		}
		else if (pCurrent->value > value)
			pCurrent = pCurrent->pLeft;
		else
			pCurrent = pCurrent->pRight;
	}
	cout << "Khong\n";
	system("pause");
	return ;
}

Tree*Insert(Tree *tree , bool &HasTree)
{
	system("cls");
	cout << "Nhap so ma ban muon them:  ";
	int value; 
	cin >> value;
	Node* pChild = new Node;
	Node* pPush = new Node;
	pPush = CreatNode(value);
	pChild = tree->root;
	bool done = false;
	if (HasTree)
	{
		do
		{
			if (value > pChild->value) {
				if (pChild->pRight == NULL) {
					pChild->pRight = pPush;
					done = true;
					cout << "\n Da them so thanh cong \n";
					system("pause");
				}
				else {
					pChild = pChild->pRight;
				}
			}
			else if (value < pChild->value)
			{
				if (pChild->pLeft == NULL) {
					pChild->pLeft = pPush;
					done = true;
					cout << "\n Da them so thanh cong \n";
					system("pause");
				}
				else {
					pChild = pChild->pLeft;
				}
			}
			else
			{
				cout << "\nso da ton tai khong the them \n";
				system("pause");
				done = true;
			}
		} while (done == false);
	}
	else
	{
		cout << "\nDa them so thanh cong\n";
		system("pause");
		tree->root = pPush;
		HasTree = true;
	}
	return tree;
}

Tree* Delete(Tree* tree , bool& HasTree)
{
	int value;
	system("cls");
	cout << " Nhap so ban muon xoa :  ";
	cin >> value;
	Node* pCurrent = new Node;
	Node* pPop = new Node;
	Node* pPrevPop = new Node;
	
	if (tree->root->value == value)
	{
		pCurrent = tree->root;
		Node* newroot = new Node;
		Node* nodedelete = new Node;
		if (pCurrent->pRight && pCurrent->pLeft)
		{
			pCurrent = pCurrent->pRight;
			while (pCurrent->pLeft)
			{
				pCurrent = pCurrent->pLeft;
			}
			newroot = tree->root->pRight;
			pCurrent->pLeft = tree->root->pLeft;
			nodedelete = tree->root;
			tree->root = newroot;
		}
		else if (pCurrent->pLeft && !pCurrent->pRight)
		{
			newroot = tree->root->pLeft;
			nodedelete = tree->root;
			tree->root = newroot;
		}
		else if (!pCurrent->pLeft && pCurrent->pRight)
		{
			newroot = tree->root->pRight;
			nodedelete = tree->root;
			tree->root = newroot;
		}
		else
		{
			nodedelete = tree->root;
			tree->root = NULL;
			HasTree = false;
		}
		delete nodedelete;
		system("cls");
		cout << "da xoa thanh cong\n";
		system("pause");
		return tree;
	}
	else
	{
		pCurrent = tree->root;
		pPrevPop = tree->root;
		do
		{
			if (pCurrent->value == value)
			{
				if (pCurrent = pPrevPop->pRight)
				{
					pPop = pCurrent;
					if (pPop->pLeft && pPop->pRight)
					{
						pCurrent = pCurrent->pRight;
						while (pCurrent->pLeft)
						{
							pCurrent = pCurrent->pLeft;
						}
						pCurrent->pLeft = pPop->pLeft;
						pPrevPop->pRight = pPop->pRight;
						delete pPop;
					}
					else if (pPop->pLeft && !pPop->pRight)
					{
						pPrevPop->pRight = pPop->pLeft;
						delete pPop;
					}
					else if (!pPop->pLeft && pPop->pRight)
					{
						pPrevPop->pRight = pPop->pRight;
						delete pPop;
					}
					else
						pPrevPop->pRight = NULL;
				}
				else
				{
					pPop = pCurrent;
					if (pPop->pLeft && pPop->pRight)
					{
						pCurrent = pCurrent->pRight;
						while (pCurrent->pLeft)
						{
							pCurrent = pCurrent->pLeft;
						}
						pCurrent->pLeft = pPop->pLeft;
						pPrevPop->pLeft = pPop->pRight;
						delete pPop;
					}
					else if (pPop->pLeft && !pPop->pRight)
					{
						pPrevPop->pLeft = pPop->pLeft;
						delete pPop;
					}
					else if (!pPop->pLeft && pPop->pRight)
					{
						pPrevPop->pLeft = pPop->pRight;
						delete pPop;
					}
					else
						pPrevPop->pLeft = NULL;

				}
				cout << "\nDa xoa node thanh cong : \n";
				system("pause");
				return tree;
			}
			else if (pCurrent->value > value)
			{
				if (pCurrent->pLeft)
				{
					pPrevPop = pCurrent;
					pCurrent = pCurrent->pLeft;
				}
				else
				{
					cout << "\n node ban chon khong ton tai \n";
					system("pause");
					return tree;
				}
			}
			else
			{
				if (pCurrent->pRight)
				{
					pPrevPop = pCurrent;
					pCurrent = pCurrent->pRight;
				}
				else
				{
					cout << "\n node ban chon khong ton tai \n";
					system("pause");
					return tree;
				}
			}
		} while (pCurrent);
	}
	cout << "\n Node ban chon khong ton tai \n";
	system("pause");
	return tree;
}

int Height(Node* root ,int height, int max)
{
	if (root->pRight)
		max = Height(root->pRight, height +1, max);
	if (root->pLeft)
		max = Height(root->pLeft, height + 1, max);
	if (height > max)
		max = height;
	return max;
}

int Size(Node* root)
{
	if (root)
		return Size(root->pLeft) + Size(root->pRight) + 1;
	else
		return 0;
	
}

void SizeProcess(Node* root)
{
	system("cls");
	cout << "Nhap gia tri cua node ban muon tinh size : " ;
	int value;
	cin >> value;
	do
	{
		if (root->value == value)
		{
			cout << "size cua node la " << Size(root)<<"\n";
			return;
		}
		else if (root->value < value)
			root = root->pRight;
		else
			root = root->pLeft;
	} while (root);
	cout << " node ban muon tim size khong ton tai\n";
	return;
}
int main()
{
	//==========Ngan Hang Bien Ham Main============
	// Bien toan ham
	// Input :bien doc file;
	// Select : bien lua chon
	// tree: bien cay
	// height : chieu cao cua cay
	int Select , height;
	Tree* tree = new Tree;
	tree = CreatTree();
	bool HasTree = false;
	do {
		system("cls");
		Menu();
		cout << "NHAP LUA CHON CUA BAN ";
		cin >> Select;
		switch (Select)
		{
		case 1:
			if (HasTree == false)
			{
				tree = CreatTreeAuto();
				HasTree = true;
			}
			else
			{
				system("cls");
				cout << "Da tao cay khong the tao cay\n";
				system("pause");
			}
			break;
		case 2:
			if (HasTree)
				SearchValue(tree);
			else
			{
				system("cls");
				cout << "Chua co cay vui long tao\n";
				system("pause");
			}
			break;
		case 3:
			tree = Insert(tree, HasTree);
			break;
		case 4:
			if (HasTree)
				tree = Delete(tree, HasTree);
			else
			{
				system("cls");
				cout << "Chua co cay vui long tao";
				system("pause");
			}
			break;
		case 5:
				if (HasTree)
				{
					system("cls");
					height = Height(tree->root,1, 1);
					cout << " Chieu cao cua cay la : " <<height<<"\n";
					system("pause");
				}
				else 
				{
					system("cls");
					cout << "Chua co cay vui long tao\n";
					system("pause");
				}
			break;
		case 6:
			if (HasTree)
			{
				system("cls");
				SizeProcess(tree->root);
				system("pause");
			}
			else
			{
				system("cls");
				cout << "Chua co cay vui long tao\n";
				system("pause");
			}
			break;
		default:
			break;
		}
	} while (Select != 0);
	system("cls");
	cout << "end\n";
	system("pause");
	return 0;
}
