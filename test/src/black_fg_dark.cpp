#include "Commons.h"

int main() {
    return !Color(Colors::black).fg().darken() == codes("30") ? SUCCESS : FAILURE;
}
