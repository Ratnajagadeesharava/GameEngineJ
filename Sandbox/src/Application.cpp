#pragma once
namespace Mango {
	__declspec(dllimport) void print();
};
void main() {
	/*__declspec(dllimport) Mango::print();*/
	Mango::print();
}