#include <stdio.h>
#include <math.h>
int main() {
	int n;
	int i;
	long int a, b, s, t;
	int c;
	long int temp1, temp2;
	long int first, second, third, fourth, fifth, sixth, seventh, eighth, nineth;
	scanf("%d", &n);
	if(n < 100) {
		for(i = 1;i <= n;i++) {
			scanf("%d", &a);
			b = (int)sqrt(a);
			if(a > 1 && a < 1000000000) {
				for(c = 2;c <= b;c++) {
					if(a % c == 0){
						break;
					}
				}
				if(c > b) {
					temp1 = a;
					first = temp1 / 100000000;
					temp2 = temp1 % 100000000;
					second = temp2 / 10000000;
					temp1 = temp2 % 10000000;
					third = temp1 / 1000000;
					temp2 = temp1 % 1000000;
					fourth = temp2 / 100000;
					temp1 = temp2 % 100000;
					fifth = temp1 / 10000;
					temp2 = temp1 % 10000;
					sixth = temp2 / 1000;
					temp1 = temp2 % 1000;
					seventh = temp1 / 100;
					temp2 = temp1 % 100;
					eighth = temp2 / 10;
					temp1 = temp2 % 10;
					nineth = temp1;
					switch(first) {
						
						case 1:
						case 3:
						case 7:
						case 9:
						 	t = nineth * 100000000 + eighth * 10000000 + seventh * 1000000 + sixth * 100000 + fifth * 10000 + fourth * 1000 + third * 100 + second * 10 + first;
							if(t == a) {
								printf("Yes\n");
							}
							break;
						case 0:
							s = first * 100000000 + second * 10000000 + third * 1000000 + fourth * 100000 + fifth * 10000 + sixth * 1000 + seventh * 100 + eighth * 10 + nineth;
							t = nineth * 100000000 + eighth * 10000000 + seventh * 1000000 + sixth * 100000 + fifth * 10000 + fourth * 1000 + third * 100 + second * 10 + first;
							if(second != 0) {
								if(t / 10 == s) {
									printf("Yes\n");
								}
								else 
									printf("No\n");
							}
							else if(second == 0) {
								if(third != 0) {
									if(t / 100 == s) {
										printf("Yes\n");
									}
									else 
										printf("No\n");
								}
								else if(third == 0) {
									if(fourth != 0) {
										if(t / 1000 == s) {
											printf("Yes\n");
										}
										else
											printf("No\n");
									}
									else if(fourth == 0) {
										if(fifth != 0) {
											if(t / 10000 == s) {
												printf("Yes\n");
											}
											else
												printf("No\n");
										}
										else if(fifth == 0) {
											if(sixth != 0) {
												if(t / 100000 == s) {
													printf("Yes\n");
												}
												else
													printf("No\n");
											}
											else if(sixth == 0) {
												if(seventh != 0) {
													if(t / 1000000 == s) {
														printf("Yes\n");
													}
													else
														printf("No\n");
												}
												else if(seventh == 0) {
													if(eighth != 0) {
														if(t / 10000000 == s) {
															printf("Yes\n");
														}
														else 
															printf("No\n");
													}
													else if(eighth == 0) {
														printf("Yes\n");
													}
												}
											}
										}
									}							
								}
								
							}
					}
				}
				else {
					printf("No\n");
				}
			}
		}
	}
	return 0;
} 

