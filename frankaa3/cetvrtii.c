/*3. Napisati program koji generira 20 sluèajnih brojeva u opsegu od 10-20 i sprema
ih u vezanu listu,
po redoslijedu generiranja, a ne sortirano.
a) Korisnik unosi jedan broj i potrebno je iz vezane liste izbrisati sva pojavljivanja
tog broja i
ispisati vezanu listu.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct _brojevi;
typedef struct _brojevi brojevi;
typedef brojevi* position;

struct _brojevi {
	int broj;
	position next;
};

int GeneriranjeBroja(position head);
int SpremanjeUListu(position head, int broj);
int IspisListe(position head);
int BrisanjeBroja(position head, int unos);


int main()
{
	srand((unsigned int)(time));

	brojevi head;
	head.next = NULL;
	int result = 0;
	int unos = 0;

	result = GeneriranjeBroja(&head);

	printf("Ovo je vasa lista: \n");
	result = IspisListe(&head);

	printf("\nunesite broj koji zelite izbrisati: \n");
	scanf("%d", &unos);

	result = BrisanjeBroja(&head, unos);
	printf("\novo je vasa lista bez tog broja: \n");
	result = IspisListe(&head);

	return 0;
}

int GeneriranjeBroja(position head)
{
	int x;
	int i;
	int result;

	for (i = 0; i < 21;i++)
	{
		x = (rand() % (20 - 10 + 1)) + 10;
		result = SpremanjeUListu(head, x);
	}



	return 0;
}


int SpremanjeUListu(position head, int broj)
{
	position temp;
	temp = (position)malloc(sizeof(brojevi));

	if (temp == NULL)
	{
		printf("nije e alociralo");
		return - 1;
	}

	temp->broj = broj;
	while (head->next != NULL)
	{
		head = head->next;
	}

	temp->next = NULL;
	head->next = temp;
	



	return 0;
}

int IspisListe(position head)
{
	head = head->next;

	while (head != NULL)
	{
		printf(" %d ", head->broj);
		head = head->next;
	}

	return 0;
}

int BrisanjeBroja(position head, int unos)
{
	position temp;
	temp = head;

	while (temp->next != NULL)
	{
		temp = head->next;
		if (temp->broj == unos)
		{
			head->next = temp->next;
			free(temp);
		}
		else
		{
			head = head->next;
		}
	}

	return 0;
}