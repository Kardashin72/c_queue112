#include "cqueue.h"

void main() {
	c_queue112 q1;
	q1.push('r');
	q1.push('q');
	q1.push('t');
	q1.push('y');
	q1.push('h');
	q1.push('j');
	q1.push('d');
	q1.push('t');
	q1.push('a');
	q1.print();
	c_queue112 q2 = q1;
	q2.print();
	c_queue112 q3;
	q3 = q2;
	q3.print();

}