#include "Commons.h"

int main() {
    return !Color(Colors::cyan).bg().brighten() == codes("106") ? SUCCESS : FAILURE;
}
