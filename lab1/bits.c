/* 
 * CS:APP Data Lab 
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#include "btest.h"
#include <limits.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team =
{
   /* Team name: Replace with either:
      Your login ID if working as a one person team
      or, ID1+ID2 where ID1 is the login ID of the first team member
      and ID2 is the login ID of the second team member */
    "515030910241", 
   /* Student name 1: Replace with the full name of first team member */
   "ZHAO shenglong",
   /* Login ID 1: Replace with the login ID of first team member */
   "515030910241",

   /* The following should only be changed if there are two team members */
   /* Student name 2: Full name of the second team member */
   "",
   /* Login ID 2: Login ID of the second team member */
   ""
};

#if 0
/*
 * STEP 2: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
#endif

/*
 * STEP 3: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce 
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 */
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 9.0.0.  Version 9.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, fourth edition, plus
   Amd. 1  and Amd. 2 and 273 characters from forthcoming  10646, fifth edition.
   (Amd. 2 was published 2016-05-01,
   see https://www.iso.org/obp/ui/#iso:std:iso-iec:10646:ed-4:v1:amd:2:v1:en) */
/* We do not support C11 <threads.h>.  */
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
	/*
	 *There is a principle in my code:
	 *	MSB of 0 and -0 are both 0;
	 *	however, x and ~x are 0 and 1(x!=TMIN)
	 *	or both 1s, x == TMIN;
	 *so the function check the MSB of x and -x, then return the MSB
	 *
	 */
	int result = ((x>>31)&1)|(((~x+1)>>31)&1);	
	return (~result)&1;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
	/*
	 * mask is used to compute the number of 1s every 4 bits
	 * To achieve this, the function every time rightly move x one bit 
	 * add the result of 4 times' addition, the number of 1s is in every 4 bits
	 * then the function try to plus these counts
	 * finally return the result
	 *
	 */
	int mask = (0x11<<24)+(0x11<<16)+(0x11<<8)+0x11;
	int count1 = mask & x;
	int count2 = mask & (x>>1);
	int count3 = mask & (x>>2);
	int count4 = mask & (x>>3);
	int count = count1 + count2 + count3 + count4;
	int binCount = count + (count>>16);
	int newMask = ((0xf<<8) + 0xf);
	int temp1 = binCount & newMask;
	int temp2 = (binCount>>4) & newMask;
	int temp = temp1 + temp2;
	int result = (temp + (temp>>8))&0xff;
  	return result;
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
	/* 
	 * First move 31 bits left, the least bit will be moved to the most left
	 * due to arithmatic shift, move the MSB to the most right,
	 * it will fill the whole int
	 *
	 */
  return (x<<31>>31);
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
	/*
	 * If x >= 0, then x>>n works well,if x < 0, it will round down
	 * so , if x < 0, we ad 1 to x>>n
	 * However , there is another problem, if x can be divided by 2^n, it doesn't need to round
	 * so function used a variable divided
	 *
	 */
	int divided =!!( ((x>>n)<<n)^x);
	return (x>>n)+((x>>31)&divided);
}
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int evenBits(void) {
	/*
	 * used a mask 0x55 which is 01010101
	 * left shift 16 bits and add 0x55 to the result
	 * it will generate 0x550055
	 * left shift 8 bits and get 0x55005500,add 0x550055 at last
	 */
  	int temp = (0x55<<16) + 0x55;
	return ((temp<<8)+temp);
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
	/*
	 * 1) n = 32, of course ,the answer is obvious
	 * 2) n <= 31, then the scale of n can represent is -2^(n-1) - 2^(n-1)-1;
	 *    if x + 2^(n-1)>=0 and 2^(n-1)-1 - x >=0; returns 1, else returns 0 
	 *
	 */
	int minusOne = ~0;
	int border = 1<<(n+minusOne);
	int uploaded = (border + (~x));
	int downloaded = x + border;
	return (((~uploaded & ~downloaded)>>31)&1)|(n>>5);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
	/*
	 * mask is used to get the least byte of given number
	 * n<<3 is intended to get the bits x is to left shift
	 * then shift x to right (n<<3)bits,return the masked number
	 */
  	return 0xff&(x>>(n<<3));
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
	/*
	 * minus is x - y;
	 * there are some conditions: x is greater than y:
	 * x - y > 0 and x - y is not overflowed 
	 * 1) x >= 0, y >= 0, OF will not happend
	 * 2) x <= 0, y <= 0, OF will not happend
	 * 3) x <= 0, y >= 0, OF may be happend, when x - y > 0, it OF;
	 * 4) x >= 0, y <= 0, OF may be happend, when x - y < 0, it OF;
	 * if x - y > 0, 1) 2) is what we want, but 3) should not be included
	 *
	 */
  
	
	int minus = x +(~y) + 1;
	int xPosyNeg = (~x) & y;
	int xNegyPos = x & (~y);
	int minusIsPos = ~minus;
	return (((minusIsPos|xPosyNeg)&(~xNegyPos))>>31)&(!!(x^y));
  
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
	/*
	 * negative number's MSB is 1
	 * so check the MSB of x
	 */
  	return !(x>>31);
}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
	/*
	 * x^y == 0 only if x == y
	 */
  	return !!(x^y);
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 60
 *   Rating: 4
 */
int isPower2(int x) {
	/*
	 * negative number is not power 2, so if MSB is 1,return 0
	 * power 2 only have one 1 bit, so count the bit of x, if result
	 * is 1 and MSB is not 1, return 1
	 */
 	int mask = (0x11<<24)+(0x11<<16)+(0x11<<8)+0x11;
	int count1 = mask & x;
	int count2 = mask & (x>>1);
	int count3 = mask & (x>>2);
	int count4 = mask & (x>>3);
	int count = count1 + count2 + count3 + count4;
	int binCount = count + (count>>16);
	int newMask = ((0xf<<8) + 0xf);
	int temp1 = binCount & newMask;
	int temp2 = (binCount>>4) & newMask;
	int temp = temp1 + temp2;
	int result = (temp + (temp>>8))&0xff; 
	int MSB = (x>>31)&1;
	return !((result^1)|MSB);
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 4 
 */
int leastBitPos(int x) {
	/*
	 * bits of x and x-1 are all equal except those before least bit
	 * x & (x-1)returns x - leastbits,
	 * then ^ returns leastbits
	 */
	int temp = x&(x+(~0));
  	return (temp^x);
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 1 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
	/*
	 * n>=1, first shift x to right 1 bit
	 * then used a mask set MSB to 1
	 * then move x to right n-1 bits
	 */
  	int mask = (0x7f<<24)+(0xff<<16)+(0xff<<8)+0xff;
	n = n + (~0);
	x = (x>>1)&mask;
	return x>>n;
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) {

	/*
	 * positiveOf returns 0x11111111 if positive overflowwed ,else returns 0
	 * negativeOf returns 0x11111111 IF NEGATIVE overflowed , else returns 0
	 * (addition & (((~positiveOf) & (~negativeOf)))) returns addition if not positiveoverflowed and not negative overflowed
	 * else ,return 0;
	 * the same as max and min
	 */
	int addition = x + y;
	int signOfX = (x>>31);
	int signOfY = (y>>31);
	int signOfXY = (addition>>31);

  	int positiveOf = (~signOfX) & (~signOfY) & signOfXY;
	int negativeOf = signOfX & signOfY & (~signOfXY);
	int min = 1<<31;
	int max = ~min;
	int result = (addition & (((~positiveOf) & (~negativeOf)))) + (max & positiveOf) + (min & negativeOf);
	return result;
}
/* 
 * tc2sm - Convert from two's complement to sign-magnitude 
 *   where the MSB is the sign bit
 *   You can assume that x > TMin
 *   Example: tc2sm(-5) = 0x80000005.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int tc2sm(int x) {
	/*
	 * value is abs(x),if x is positive or 0, value = x, else x = -x(x>Tmin)
	 * sign is MSB of x, sign 0x11111111 negative, sign 0 nonnegative
	 * sign & (~x+1) returns abs(x) if x < 0, 0 else
	 * x&(~sign) returns x if x >= 0, 0 else
	 */
	int sign = x>>31;
	int value = (sign&(~x+1))+(x&(~sign));
  	return value+(sign<<31);
}
