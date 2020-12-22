#include<iostream>
using namespace std;
typedef int faq;
struct Emal
{
	Emal* next,
		* prev;
	faq inf;
};
void dob(Emal*& first, Emal*& last, faq i)
{
	Emal* tmp = new Emal; // 1
	tmp->inf = i; // 2
	tmp->next = NULL; // 3
	if (last != NULL)
		last->next = tmp; // 4
	tmp->prev = last; // 5
	last = tmp; // 6
	if (first == NULL)
		first = tmp;
}
faq pop(Emal*& first, Emal*& last)
{
	Emal* tmp = first->next; // 1
	faq value = first->inf; // 2
	delete first; // 3
	first = tmp; // 4
	if (first == NULL)
		last = NULL; // 5
	else
		first->prev = NULL; // 6
	return value;
}
void q1 (Emal*& first, Emal*& last)
{
	faq a;
	cout << "Vvedit chislo:  ";
	cin >> a;
	while (last!= NULL /*&& last->prev!= NULL*/)
	{
		
		//(first->inf)= (first->inf)+a;
		(last->inf) = (last->inf) + a;
		//first = first->next;
		last = last->prev;
	}
}
int main()
{
	Emal* first = NULL;
	Emal* last = NULL;
	for (int i = 1; i < 20; i++)
		dob(first, last,i);

	q1(first, last);

	while ( first != NULL)
	{
		cout << pop(first, last) << "  ";
	}


}