#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <math.h>
struct STree
{
	int data;
	STree *right, *left;
};

void create(int, STree*&);
void print(STree*(&), int);

