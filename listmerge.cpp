/*
 * =====================================================================================
 *
 *       Filename:  listmerge.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/20/2017 11:39:55 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <map>
#include <list>

using namespace std;

struct Node {
    int value;
    Node *next;
    Node(int v):value(v){}
};

/* 创建一个链表，1->2->3->4->5->6->7*/
Node *CreateList1()
{
    Node *head;
    Node *n1 = new Node(1);
    Node *n3 = new Node(3);
    Node *n5 = new Node(5);
    Node *n7 = new Node(7);
    Node *n9 = new Node(9);
    head = n1;
    n1->next = n3;
    n3->next = n5;
    n5->next = n7;
    n7->next = n9;
    n9->next = NULL;
    return head;
}

Node *CreateList2()
{
    Node *head;
    Node *n1 = new Node(2);
    Node *n3 = new Node(4);
    Node *n5 = new Node(6);
    Node *n7 = new Node(8);
    Node *n9 = new Node(10);
    head = n1;
    n1->next = n3;
    n3->next = n5;
    n5->next = n7;
    n7->next = n9;
    n9->next = NULL;
    return head;
}


void FreeList(Node *head)
{
    if (head == NULL)
        return;
    Node *tmp = NULL;
    while (head != NULL) {
        tmp = head->next;
        delete head;
        head = tmp;
    }
}

void VisitList(Node *head)
{
    if (head == NULL) {
        std::cout << "NULL" << std::endl;
    }
    Node *tmp = head;
    while (tmp != NULL) {
        std::cout << tmp->value << "->";
        tmp = tmp->next;
    }
    std::cout << "NULL" << std::endl;
}

Node *ListMerge(Node *head1, Node *head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head1;
    Node *head = NULL;
    Node *p1 = head1;
    Node *p2 = head2;
    if (head1->value < head2->value) {
        head = head1;
        p1 = head1->next;
    } else {
        head = head2;
        p2 = head2->next;
    }

    Node *p = head;
    while(p1 && p2) {
        if (p1->value < p2->value) {
            p->next = p1;
            p1 = p1->next;
        } else {
            p->next = p2;
            p2 = p2->next;
        }
        p = p->next;
    }
    if (p1) {
        p->next = p1;
    } else if(p2) {
        p->next = p2;
    }
    return head;
}

typedef struct _UdpFlood
{
    int ip;
    int vsys;
}UdpFlood;

typedef map<int, UdpFlood> UdpFloodHashmap;
typedef UdpFloodHashmap::iterator  UdpFloodIter;

#define NUM 5

int main(void)
{
    Node *head1 = CreateList1();
    Node *head2 = CreateList2();
    std::cout << "list1 : ";
    VisitList(head1);
    std::cout << "list2 : ";
    VisitList(head2);
    std::cout << "Merge : ";
    Node *head = ListMerge(head1, head2);
    VisitList(head);
    FreeList(head);

    UdpFloodHashmap udpflood_hash_table[NUM];
    for (int i = 0; i < NUM; i++) {
        UdpFlood udpflood = {10, 2*i};
        udpflood_hash_table[i].insert(std::make_pair(i, udpflood));
    }
    for (int i = 0; i < NUM; i++) {
        UdpFloodIter iter = udpflood_hash_table[i].begin();
        std::cout << "hash " << i << " : " << std::endl;
        for (; iter != udpflood_hash_table[i].end(); ++iter) {
            std::cout << "key " << iter->first
                      << "value.ip " << (iter->second).ip
                      << "value.vsys " << (iter->second).vsys
                      << std::endl;
        }
        std::cout << std::endl;
    }
    
     std::list<int> second[NUM];
     for (int i = 0; i < NUM; i++) {
        second[i] = std::list<int>(1, 1);
     }
     for (int i = 0; i < NUM; i++) {
        std:cout << "list " << i << " : ";
        for (std::list<int>::iterator it = second[i].begin(); it != second[i].end(); it++)
              std::cout << *it << ' ';
        std::cout << std::endl;
    }
    return 0;
}

