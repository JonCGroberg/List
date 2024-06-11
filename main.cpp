#include "List.h"
#include <string>

using namespace std;

int main() {
    List<int> ints;
    ints.Push(1);
    ints.Push(3);
    ints.Push(2);
    ints.Print();

    List<string> strings;
    strings.Push("hello");
    strings.Push("world");
    strings.Print();

    return 1;
}
