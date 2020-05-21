#include<iostream>
#include<algorithm>
#include<memory.h>

#define MAX 25

using namespace std;

int cube[MAX];

bool Check()
{
	for (int i = 1; i < MAX; i += 4)
	{
		for (int j = 0; j < 4; j++)
		{
			if (cube[i] != cube[i + j])
				return false;
		}
	}
	return true;
}

void Rotate_front1()
{
	swap(cube[10], cube[21]);	swap(cube[12], cube[23]);
	swap(cube[10], cube[2]);	swap(cube[12], cube[4]);
	swap(cube[10], cube[26]);	swap(cube[12], cube[8]);
}

void Rotate_front2()
{
	swap(cube[9], cube[22]);	swap(cube[11], cube[24]);
	swap(cube[9], cube[1]);		swap(cube[11], cube[3]);
	swap(cube[9], cube[5]);	swap(cube[11], cube[7]);
}

void Rotate_back1()
{
	swap(cube[10], cube[6]);	swap(cube[12], cube[8]);
	swap(cube[10], cube[2]);	swap(cube[12], cube[4]);
	swap(cube[10], cube[21]);	swap(cube[12], cube[23]);
}

void Rotate_back2()
{
	swap(cube[9], cube[5]);		swap(cube[11], cube[7]);
	swap(cube[9], cube[1]);		swap(cube[11], cube[3]);
	swap(cube[9], cube[22]);	swap(cube[11], cube[24]);
}

void Rotate_left1()
{
	swap(cube[11], cube[13]);	swap(cube[12], cube[15]);
	swap(cube[11], cube[2]);	swap(cube[12], cube[1]);
	swap(cube[11], cube[20]);	swap(cube[12], cube[18]);
}

void Rotate_left2()
{
	swap(cube[9], cube[14]);	swap(cube[10], cube[16]);
	swap(cube[9], cube[4]);		swap(cube[10], cube[3]);
	swap(cube[9], cube[17]);	swap(cube[10], cube[17]);
}

void Rotate_right1()
{
	swap(cube[11], cube[20]);	swap(cube[12], cube[18]);
	swap(cube[11], cube[1]);	swap(cube[12], cube[2]);
	swap(cube[11], cube[15]);	swap(cube[12], cube[13]);
}

void Rotate_right2()
{
	swap(cube[9], cube[19]);	swap(cube[10], cube[17]);
	swap(cube[9], cube[3]);		swap(cube[10], cube[3]);
	swap(cube[9], cube[14]);	swap(cube[10], cube[16]);
}

void Rotate_up1()
{
	swap(cube[22], cube[14]);	swap(cube[21], cube[13]);
	swap(cube[22], cube[6]);	swap(cube[21], cube[5]);
	swap(cube[22], cube[18]);	swap(cube[21], cube[17]);
}

void Rotate_up2()
{
	swap(cube[24], cube[16]);	swap(cube[23], cube[15]);
	swap(cube[24], cube[8]);	swap(cube[23], cube[7]);
	swap(cube[24], cube[20]);	swap(cube[23], cube[19]);
}

void Rotate_down1()
{
	swap(cube[22], cube[18]);	swap(cube[21], cube[17]);
	swap(cube[22], cube[6]);	swap(cube[21], cube[5]);
	swap(cube[22], cube[14]);	swap(cube[21], cube[13]);
}

void Rotate_down2()
{
	swap(cube[24], cube[20]);	swap(cube[23], cube[19]);
	swap(cube[24], cube[8]);	swap(cube[23], cube[7]);
	swap(cube[24], cube[16]);	swap(cube[23], cube[15]);
}

bool Simulation()
{
	int tmp[MAX];
	memcpy(tmp, cube, sizeof(cube));	Rotate_front1();
	if (Check())
		return true;
	memcpy(cube, tmp, sizeof(cube));

	memcpy(tmp, cube, sizeof(cube));	Rotate_front2();
	if (Check())
		return true;
	memcpy(cube, tmp, sizeof(cube));

	memcpy(tmp, cube, sizeof(cube));	Rotate_back1();
	if (Check())
		return true;
	memcpy(cube, tmp, sizeof(cube));

	memcpy(tmp, cube, sizeof(cube));	Rotate_back2();
	if (Check())
		return true;
	memcpy(cube, tmp, sizeof(cube));

	memcpy(tmp, cube, sizeof(cube));	Rotate_left1();
	if (Check())
		return true;
	memcpy(cube, tmp, sizeof(cube));

	memcpy(tmp, cube, sizeof(cube)); Rotate_left2();
	if (Check())
		return true;
	memcpy(cube, tmp, sizeof(cube));

	memcpy(tmp, cube, sizeof(cube)); Rotate_right1();
	if (Check())
		return true;
	memcpy(cube, tmp, sizeof(cube));

	memcpy(tmp, cube, sizeof(cube)); Rotate_right2();
	if (Check())
		return true;
	memcpy(cube, tmp, sizeof(cube));

	memcpy(tmp, cube, sizeof(cube)); Rotate_up1();
	if (Check())
		return true;
	memcpy(cube, tmp, sizeof(cube));

	memcpy(tmp, cube, sizeof(cube)); Rotate_up2();
	if (Check())
		return true;
	memcpy(cube, tmp, sizeof(cube));

	memcpy(tmp, cube, sizeof(cube)); Rotate_down1();
	if (Check())
		return true;
	memcpy(cube, tmp, sizeof(cube));

	memcpy(tmp, cube, sizeof(cube)); Rotate_down2();
	if (Check())
		return true;
	memcpy(cube, tmp, sizeof(cube));

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	for (int i = 1; i < MAX; i++)
		cin >> cube[i];

	if (Simulation())
		cout << true << endl;
	else
		cout << false << endl;
}