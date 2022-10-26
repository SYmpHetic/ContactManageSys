#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct date
{
	int year;
	int month;
	int day;
}type_birth;

typedef struct contacts
{
	int num;
	char name[20];
	type_birth date;
	char tel1[20];
	char tel2[20];
	char company[40];
	char email[20];
}type_contact;


char* delete_space(char* str)
{
	char* str_c = str;
	int i, j = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' '&&str[i]!='\n')
			str_c[j++] = str[i];
	}
	str_c[j] = '\0';
	str = str_c;
}

void menu()
{
	system("cls");
	printf("+=---------------ͨѶ¼����ϵͳ-----------------=+\n");
	printf(" |                                              |\n");
	printf(" |              1.�������ϵ��                  |\n");
	printf(" |              2.��ʾ������ϵ��                |\n");
	printf(" |              3.��ѯ��ϵ��                    |\n");
	printf(" |              4.�޸���ϵ����Ϣ                |\n");
	printf(" |              5.ɾ����ϵ��                    |\n");
	printf(" |              6.���沢�˳�                    |\n");
	printf(" |                                              |\n");
	printf("+=--------------ͨѶ¼����ϵͳ------------------=+\n");
}

//�������б������Ϣд��txt�ļ�����
void write_txt(type_contact contacts[100],int count)
{
	FILE* fp;
	fp = fopen("contacts.txt", "w+");
	for (int i = 0; i <= count-1; i++)
	{
		if (i != 0)
		{
			fprintf(fp, "\n");
		}
		fprintf(fp, "%-4d%-8s%-16s%-16s%-6d%-3d%-10d%-40s%-20s", i + 1, contacts[i].name, contacts[i].tel1, contacts[i].tel2, contacts[i].date.year, contacts[i].date.month, contacts[i].date.day, contacts[i].company, contacts[i].email);
	}
	fclose(fp);
}


void new_contact()//1
{
	char new_name[20];
	char new_tel1[20];
	char new_tel2[20];
	type_birth new_date;
	char new_company[40];
	char new_email[20];
	system("cls");
	//����
		//��������
	printf("����������ϵ��������\n");
	scanf("%s", &new_name);

		//�绰����
			//�绰1
	printf("������绰1��\n");
	scanf("%s", &new_tel1);
	int flag = 0;
	while (flag == 0)
	{
		flag = 1;
		if (strlen(new_tel1) != 11)
		{
			flag = 0;
			printf("�绰1��ʽ���������������룺\n");
			scanf("%s", &new_tel1);
		}
		else
		{
			for (int i = 0; i <= 10; i++)
			{
				if (new_tel1[i] < '0' || new_tel1[i]>'9')
				{
					flag = 0;
					printf("�绰1��ʽ���������������룺\n");
					scanf("%s", &new_tel1);
					break;
				}
			}
		}
	}
			//�绰2
	printf("������绰2��\n");
	scanf("%s", &new_tel2);
	flag = 0;
	while (flag == 0)
	{
		flag = 1;
		if (strlen(new_tel2) != 11)
		{
			flag = 0;
			printf("�绰2��ʽ���������������룺\n");
			scanf("%s", &new_tel2);
		}
		else
		{
			for (int i = 0; i <= 10; i++)
			{
				if (new_tel2[i] < '0' || new_tel2[i]>'9')
				{
					flag = 0;
					printf("�绰2��ʽ���������������룺\n");
					scanf("%s", &new_tel2);
					break;
				}
			}
		}
	}
		//�������ڲ���
			//���
	printf("������������\n");
	scanf("%d", &new_date.year);
	flag = 0;
	while (flag == 0)
	{
		flag = 1;
		if (new_date.year > 2021 || new_date.year <= 0)
		{
			flag = 0;
			printf("��ݸ�ʽ���������������룺\n");
			scanf("%d", &new_date.year);
		}
	}
			//�·�
	printf("����������·�\n");
	scanf("%d", &new_date.month);
	flag = 0;
	while (flag == 0)
	{
		flag = 1;
		if (new_date.month > 12 || new_date.month <= 0)
		{
			flag = 0;
			printf("�·ݸ�ʽ���������������룺\n");
			scanf("%d", &new_date.month);
		}
	}
			//��
	printf("�������������\n");
	scanf("%d", &new_date.day);
	flag = 0;
	while (flag == 0)
	{
		flag = 1;
		if (new_date.day > 31 || new_date.day <= 0)
		{
			flag = 0;
			printf("�ո�ʽ���������������룺\n");
			scanf("%d", &new_date.day);
		}
	}
		//������λ����
	printf("�����빤����λ��\n");
	scanf("%s", &new_company);

		//�������䲿��
	printf("������������䣺\n");
	scanf("%s", &new_email);
	flag = 0;
	while (flag == 0)
	{
		for (int i = 0; i <= 19; i++)
		{
			if (new_email[i] == '@')
			{
				flag = 1;
				break;
			}

		}
		if (flag == 0)
		{
			printf("���������ʽ���������������룺\n");
			scanf("%s", &new_email);
		}
	}
	//д���ļ�
	FILE* fp;
	char buffer[256];
	type_contact contacts[100];
	fp = fopen("contacts.txt", "a+");
	int i;
	for (i = 0; i < 100; i++)
	{
		if (feof(fp))
		{
			break;
		}
		fgets(buffer, 5, fp);
		contacts[i].num = atoi(buffer);

		fgets(buffer, 9, fp);
		strcpy(contacts[i].name, buffer);
		delete_space(contacts[i].name);

		fgets(buffer, 17, fp);
		strcpy(contacts[i].tel1, buffer);
		delete_space(contacts[i].tel1);

		fgets(buffer, 17, fp);
		strcpy(contacts[i].tel2, buffer);
		delete_space(contacts[i].tel2);

		fgets(buffer, 7, fp);
		contacts[i].date.year = atoi(buffer);

		fgets(buffer, 4, fp);
		contacts[i].date.month = atoi(buffer);

		fgets(buffer, 11, fp);
		contacts[i].date.day = atoi(buffer);

		fgets(buffer, 41, fp);
		strcpy(contacts[i].company, buffer);
		delete_space(contacts[i].company);

		fgets(buffer, 22, fp);
		strcpy(contacts[i].email, buffer);
		delete_space(contacts[i].email);
	}
	fprintf(fp, "\n");
	fprintf(fp, "%-4d%-8s%-16s%-16s%-6d%-3d%-10d%-40s%-20s",i+1,new_name,new_tel1,new_tel2,new_date.year,new_date.month,new_date.day,new_company,new_email);
	fclose(fp);
	printf("�������ϵ�˳ɹ���");
}

void show_contact()//2
{
	system("cls");
	FILE* fp;
	char buffer[256];
	fp = fopen("contacts.txt", "a+");
	printf("----------------------------------------------------ͨѶ¼�б�----------------------------------------------------------\n");
	printf("��� ����	�绰1		�绰2	       ��������		������ַ				��������\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	while (!feof(fp))
	{
		fgets(buffer, 256, fp);
		printf("%s", buffer);
		printf("\n");
	}
	fclose(fp);
	printf("\n");
}

void search_contact()//3
{
	type_contact contacts[100];
	int flag = 0;
	FILE* fp;
	char buffer[64];
	fp = fopen("contacts.txt", "a + ");
	for (int i = 0; i < 100; i++)
	{
		fgets(buffer, 5, fp);
		contacts[i].num = atoi(buffer);

		fgets(buffer, 9, fp);
		strcpy(contacts[i].name, buffer);
		delete_space(contacts[i].name);

		fgets(buffer, 17, fp);
		strcpy(contacts[i].tel1, buffer);
		delete_space(contacts[i].tel1);

		fgets(buffer, 17, fp);
		strcpy(contacts[i].tel2, buffer);
		delete_space(contacts[i].tel2);

		fgets(buffer, 7, fp);
		contacts[i].date.year = atoi(buffer);

		fgets(buffer, 4, fp);
		contacts[i].date.month = atoi(buffer);

		fgets(buffer, 11, fp);
		contacts[i].date.day = atoi(buffer);

		fgets(buffer, 41, fp);
		strcpy(contacts[i].company, buffer);
		delete_space(contacts[i].company);

		fgets(buffer, 22, fp);
		strcpy(contacts[i].email, buffer);
		delete_space(contacts[i].email);

		if (feof(fp))
		{
			break;
		}
	}

	while (flag == 0)
	{
		flag = 1;
		system("cls");
		printf("+=---------------ͨѶ¼����ϵͳ-----------------=+\n");
		printf(" |                                              |\n");
		printf(" |              ��ѡ���ѯ��ʽ                  |\n");
		printf(" |              1.��������ѯ                    |\n");
		printf(" |              2.���绰��ѯ                    |\n");
		printf(" |              3.��email��ѯ                   |\n");
		printf(" |              4.����                          |\n");
		printf(" |                                              |\n");
		printf("+=--------------ͨѶ¼����ϵͳ------------------=+\n");
		printf("������Ҫִ�е���Ŀ���֣�");
		int x;
		scanf("%d", &x);
		if (x != 1 && x != 2 && x != 3 && x != 4)
		{
			system("cls");
			flag = 0;
			printf("������Ĳ�ѯ���������ڣ����������룺\n");
			system("pause");
		} 
		//��������ѯ
		if (x == 1)
		{
			char search_name[20];
			system("cls");
			printf("������Ҫ��ѯ��������\n");
			scanf("%s", &search_name);
			int find = 0;
			int find_num[100];
			int i, j = 0;
			for (i = 0; i <= 99; i++)
			{
				if (strcmp(search_name, contacts[i].name) == 0)
				{
					find = 1;
					find_num[j] = i;
					j++;
				}
			}

			if (find)
			{
				system("cls");
				printf("���ҵ���Ӧ����ϵ��\n");
				printf("------------------------------------------------------------------------------------------------------------------------\n");
				printf("��� ����	�绰1		�绰2	        ��������		������ַ				��������\n");
				printf("------------------------------------------------------------------------------------------------------------------------\n");
				for (int k = 0; k <= j - 1; k++)
				{
					printf("%-4d%-8s%-16s%-16s%-6d%-3d%-10d%-40s%-20s\n",contacts[find_num[k]].num, contacts[find_num[k]].name, contacts[find_num[k]].tel1, contacts[find_num[k]].tel2, contacts[find_num[k]].date.year, contacts[find_num[k]].date.month, contacts[find_num[k]].date.day, contacts[find_num[k]].company, contacts[find_num[k]].email);
				}

			}
			else
			{
				system("cls");
				printf("û���ҵ���Ӧ����ϵ��\n");
			}
		}
		//���绰��ѯ
		if (x == 2)
		{
			system("cls");
			char search_tel[20];
			printf("������Ҫ��ѯ�ĵ绰���룺\n");
			scanf("%s", &search_tel);
			int find = 0;
			int find_num[100];
			int i, j = 0;
			for (i = 0; i <= 99; i++)
			{
				if (strcmp(search_tel, contacts[i].tel1) == 0||strcmp(search_tel,contacts[i].tel2)==0)
				{
					find = 1;
					find_num[j] = i;
					j++;
				}
			}

			if (find)
			{
				system("cls");
				printf("���ҵ���Ӧ����ϵ��\n");
				printf("------------------------------------------------------------------------------------------------------------------------\n");
				printf("��� ����	�绰1		�绰2	        ��������		������ַ				��������\n");
				printf("------------------------------------------------------------------------------------------------------------------------\n");
				for (int k = 0; k <= j - 1; k++)
				{
					printf("%-4d%-8s%-16s%-16s%-6d%-3d%-10d%-40s%-20s\n",contacts[find_num[k]].num , contacts[find_num[k]].name, contacts[find_num[k]].tel1, contacts[find_num[k]].tel2, contacts[find_num[k]].date.year, contacts[find_num[k]].date.month, contacts[find_num[k]].date.day, contacts[find_num[k]].company, contacts[find_num[k]].email);
				}

			}
			else
			{
				system("cls");
				printf("û���ҵ���Ӧ����ϵ��\n");
			}
		}
		//��email��ѯ
		if (x == 3)
		{
			system("cls");
			char search_email[20];
			printf("������Ҫ��ѯ��email��\n");
			scanf("%s", &search_email);
			int find = 0;
			int find_num[100];
			int i, j = 0;
			for (i = 0; i <= 99; i++)
			{
				if (strcmp(search_email, contacts[i].email) == 0)
				{
					find = 1;
					find_num[j] = i;
					j++;
				}
			}

			if (find)
			{
				system("cls");
				printf("���ҵ���Ӧ����ϵ��\n");
				printf("------------------------------------------------------------------------------------------------------------------------\n");
				printf("��� ����	�绰1		�绰2	        ��������		������ַ			��������\n");
				printf("------------------------------------------------------------------------------------------------------------------------\n");
				for (int k = 0; k <= j - 1; k++)
				{
					printf("%-4d%-8s%-16s%-16s%-6d%-3d%-10d%-40s%-20s\n", contacts[find_num[k]].num, contacts[find_num[k]].name, contacts[find_num[k]].tel1, contacts[find_num[k]].tel2, contacts[find_num[k]].date.year, contacts[find_num[k]].date.month, contacts[find_num[k]].date.day, contacts[find_num[k]].company, contacts[find_num[k]].email);
				}

			}
			else
			{
				system("cls");
				printf("û���ҵ���Ӧ����ϵ��\n");
			}
		}
		if (x == 4)
		{
			printf("����\n");
		}
	}
	
	
	
}

void alt_contact()//4
{
	type_contact contacts[100];
	int flag = 0; int count = 0;//����Ŀǰ�ж�������¼
	FILE* fp;
	char buffer[64];
	fp = fopen("contacts.txt", "a + ");
	for (int i = 0; i < 100; i++)
	{
		if (feof(fp))
		{
			count = i;
			break;
		}

		fgets(buffer, 5, fp);
		contacts[i].num = atoi(buffer);
		
		fgets(buffer, 9, fp);
		strcpy(contacts[i].name, buffer);
		delete_space(contacts[i].name);

		fgets(buffer, 17, fp);
		strcpy(contacts[i].tel1, buffer);
		delete_space(contacts[i].tel1);

		fgets(buffer, 17, fp);
		strcpy(contacts[i].tel2, buffer);
		delete_space(contacts[i].tel2);

		fgets(buffer, 7, fp);
		contacts[i].date.year = atoi(buffer);

		fgets(buffer, 4, fp);
		contacts[i].date.month = atoi(buffer);

		fgets(buffer, 11, fp);
		contacts[i].date.day = atoi(buffer);

		fgets(buffer, 41, fp);
		strcpy(contacts[i].company, buffer);
		delete_space(contacts[i].company);

		fgets(buffer, 22, fp);
		strcpy(contacts[i].email, buffer);
		delete_space(contacts[i].email);
	}
		//�����������޸�
	char search_name[20];
	system("cls");
	printf("������Ҫ�޸ĵ���ϵ��������\n");
	scanf("%s", &search_name);
	int find = 0;
	int find_num[100];
	int i, j = 0;
	for (i = 0; i <= 99; i++)
	{
		if (strcmp(search_name, contacts[i].name) == 0)
		{
			find = 1;
			find_num[j] = i;
			j++;
		}
	}

	if (find)
	{
		system("cls");
		printf("���ҵ���Ӧ����ϵ��\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("��� ����	�绰1		�绰2	      ��������			������ַ		  	  ��������\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		int k = 0;
		for (k; k <= j - 1; k++)
		{
			printf("%-4d%-8s%-16s%-16s%-6d%-4d%-10d%-40s%-20s\n",contacts[find_num[k]].num, contacts[find_num[k]].name, contacts[find_num[k]].tel1, contacts[find_num[k]].tel2, contacts[find_num[k]].date.year, contacts[find_num[k]].date.month, contacts[find_num[k]].date.day, contacts[find_num[k]].company, contacts[find_num[k]].email);
		}		
		printf("������Ҫ�޸ĵ���ϵ�˱��:\n");
		int x;
		int jud1 = 1;
		while (jud1)
		{
			jud1 = 0;
			scanf("%d", &x);
			if (x==find_num[0]+1||x==find_num[1]+1||x==find_num[2]+1||x==find_num[3]+1||x==find_num[4]+1||x==find_num[5]+1)
			{
				int jud2 = 1;
				while (jud2)
				{
					jud2 = 0;
					system("cls");
					printf("+=---------------ͨѶ¼����ϵͳ-----------------=+\n");
					printf(" |                                              |\n");
					printf(" |              ��ѡ���޸�����                  |\n");
					printf(" |              1.�޸�����                      |\n");
					printf(" |              2.�޸ĵ绰1                     |\n");
					printf(" |              3.�޸ĵ绰2                     |\n");
					printf(" |              4.�޸ĳ�������                  |\n");
					printf(" |              5.�޸Ĺ�����λ                  |\n");
					printf(" |              6.�޸�email                     |\n");
					printf(" |              7.����                          |\n");
					printf(" |                                              |\n");
					printf("+=--------------ͨѶ¼����ϵͳ------------------=+\n");
					printf("������Ҫִ�е���Ŀ���֣�");
					int y;
					scanf("%d", &y);
					if (y != 1 && y != 2 && y != 3 && y != 4 && y != 5 && y != 6 && y != 7)
					{
						jud2 = 1;
						printf("�������벻��������������\n");
						system("pause");
					}
					else
					{
						if (y == 1)//�޸�����
						{
							char change_name[20];
							printf("������Ҫ�޸ĵ�������\n");
							scanf("%s", &change_name);
							strcpy(contacts[x - 1].name, change_name);
							write_txt(contacts,count);
							printf("�޸����\n");
						}
						if (y == 2)//�޸ĵ绰1
						{
							char change_tel1[20];
							printf("������Ҫ�޸ĵĵ绰��\n");
							scanf("%s", &change_tel1);
							flag = 0;
							while (flag == 0)
							{
								flag = 1;
								if (strlen(change_tel1) != 11)
								{
									flag = 0;
									printf("�绰��ʽ���������������룺\n");
									scanf("%s", &change_tel1);
								}
								else
								{
									for (int i = 0; i <= 10; i++)
									{
										if (change_tel1[i] < '0' || change_tel1[i]>'9')
										{
											flag = 0;
											printf("�绰��ʽ���������������룺\n");
											scanf("%s",&change_tel1);
											break;
										}
									}
								}
							}
							strcpy(contacts[x-1].tel1,change_tel1);
							write_txt(contacts,count);
							printf("�޸����\n");
						}
						if (y == 3)//�޸ĵ绰2
						{
							char change_tel2[20];
							printf("������Ҫ�޸ĵĵ绰��\n");
							scanf("%s", &change_tel2);
							flag = 0;
							while (flag == 0)
							{
								flag = 1;
								if (strlen(change_tel2) != 11)
								{
									flag = 0;
									printf("�绰��ʽ���������������룺\n");
									scanf("%s", &change_tel2);
								}
								else
								{
									for (int i = 0; i <= 10; i++)
									{
										if (change_tel2[i] < '0' || change_tel2[i]>'9')
										{
											flag = 0;
											printf("�绰��ʽ���������������룺\n");
											scanf("%s", &change_tel2);
											break;
										}
									}
								}
							}
							strcpy(contacts[x - 1].tel2, change_tel2);
							write_txt(contacts,count);
							printf("�޸����\n");
						}
						if (y == 4)//�޸ĳ������� 
						{
							int change_year; int change_month; int change_day;

							printf("������Ҫ�޸ĵĳ�����ݣ�\n");
							scanf("%d", &change_year);
							flag = 0;
							while (flag == 0)
							{
								flag = 1;
								if (change_year > 2021 || change_year <= 0)
								{
									flag = 0;
									printf("��ݸ�ʽ���������������룺\n");
									scanf("%d", &change_year);
								}
							}
							contacts[x - 1].date.year = change_year;

							printf("������Ҫ�޸ĵĳ����·ݣ�\n");
							scanf("%d", &change_month);
							flag = 0;
							while (flag == 0)
							{
								flag = 1;
								if (change_month > 12 || change_month <= 0)
								{
									flag = 0;
									printf("�·ݸ�ʽ���������������룺\n");
									scanf("%d", &change_month);
								}
							}
							contacts[x - 1].date.month = change_month;

							printf("������Ҫ�޸ĵĳ������ڣ�\n");
							scanf("%d", &change_day);
							flag = 0;
							while (flag == 0)
							{
								flag = 1;
								if (change_day > 31 || change_day <= 0)
								{
									flag = 0;
									printf("�ո�ʽ���������������룺\n");
									scanf("%d", &change_day);
								}
							}
							contacts[x - 1].date.day = change_day; 
							write_txt(contacts,count);
							printf("�޸����\n");
						}
						if (y == 5)//�޸Ĺ�����λ
						{
							char new_company[40];
							printf("������Ҫ�޸ĵĹ�����λ��\n");
							scanf("%s", &new_company);
							strcpy(contacts[x - 1].company, new_company);
							write_txt(contacts,count);
							printf("�޸����\n");
						}
						if (y == 6)//�޸�email
						{
							char new_email[20];
							printf("������Ҫ�޸ĵĵ������䣺\n");
							scanf("%s", &new_email);
							flag = 0;
							while (flag == 0)
							{
								for (int i = 0; i <= 19; i++)
								{
									if (new_email[i] == '@')
									{
										flag = 1;
										break;
									}

								}
								if (flag == 0)
								{
									printf("���������ʽ���������������룺\n");
									scanf("%s", &new_email);
								}
							}
							strcpy(contacts[x - 1].email, new_email);
							write_txt(contacts,count);
							printf("�޸����");
						}
						if (y == 7)//����
						{
							printf("����\n");
						}
					}
				}
			}
			else
			{
				jud1 = 1;
				printf("�������벻��������������\n");
				system("pause");
			}
		}
	}
	else
	{
		system("cls");
		printf("û���ҵ���Ӧ����ϵ��\n");
	}
}

void delete_contact()//5
{
	type_contact contacts[100];
	int flag = 0; int count = 0;//����Ŀǰ�ж�������¼
	FILE* fp;
	char buffer[64];
	fp = fopen("contacts.txt", "a + ");
	for (int i = 0; i < 100; i++)
	{
		if (feof(fp))
		{
			count = i;
			break;
		}

		fgets(buffer, 5, fp);
		contacts[i].num = atoi(buffer);

		fgets(buffer, 9, fp);
		strcpy(contacts[i].name, buffer);
		delete_space(contacts[i].name);

		fgets(buffer, 17, fp);
		strcpy(contacts[i].tel1, buffer);
		delete_space(contacts[i].tel1);

		fgets(buffer, 17, fp);
		strcpy(contacts[i].tel2, buffer);
		delete_space(contacts[i].tel2);

		fgets(buffer, 7, fp);
		contacts[i].date.year = atoi(buffer);

		fgets(buffer, 4, fp);
		contacts[i].date.month = atoi(buffer);

		fgets(buffer, 11, fp);
		contacts[i].date.day = atoi(buffer);

		fgets(buffer, 41, fp);
		strcpy(contacts[i].company, buffer);
		delete_space(contacts[i].company);

		fgets(buffer, 22, fp);
		strcpy(contacts[i].email, buffer);
		delete_space(contacts[i].email);
	}
	show_contact();
	int x;
	int jud = 0;
	printf("������Ҫɾ������ϵ�˱��:\n");
	scanf("%d", &x);
	printf("ѡ��ɾ��%d����ϵ�ˣ�����:%s��ȷ���𣿣�ȷ��������1,��������Ĭ��ȡ�����������˵���\n", contacts[x - 1].num, contacts[x - 1].name);
	scanf("%d", &jud);
	if (jud)
	{
		for (int i = x - 1; i <= count - 1; i++)
		{
			contacts[x - 1].num = contacts[x].num;
			strcpy(contacts[x - 1].name, contacts[x].name);
			strcpy(contacts[x - 1].tel1, contacts[x].tel1);
			strcpy(contacts [x - 1].tel2, contacts[x].tel2);
			contacts[x - 1].date.year = contacts[x].date.year;
			contacts[x - 1].date.month = contacts[x].date.month;
			contacts[x - 1].date.day = contacts[x].date.day;
			strcpy(contacts[x - 1].company, contacts[x].company);
			strcpy(contacts[x - 1].email, contacts[x].email);
			count--;
		}
		write_txt(contacts, count);
		printf("ɾ��������¼�ɹ�\n");
	}
	else
	{
		printf("����\n");
	}
}

void save_and_quit()//6
{
	printf("ллʹ�ã��ټ���");
	exit(0);
}


int select()
{
	printf("������Ҫִ�е���Ŀ���֣�");
	int x;
	scanf("%d", &x);
	switch (x)
	{
	case 1: new_contact(); system("pause");  break;
	case 2: show_contact(); system("pause");  break;
	case 3: search_contact(); system("pause");  break;
	case 4: alt_contact(); system("pause");  break;
	case 5: delete_contact(); system("pause");  break;
	case 6: save_and_quit(); system("pause"); break;
	default:printf("���벻�Ϲ淶������������1-6\n"); system("pause"); break;
	}
	return x;
}
main()
{
	for (;;)
	{
		system("mode con cols=160 lines=35");
		menu();
		select();
	}

	return 0;
}