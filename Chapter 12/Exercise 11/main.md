```
#include <string>
#include <vector>
#include "Str.h"

std::vector<Str> split(const Str& str, const Str& token) {
    std::vector<Str> result;
    Str current;

    for (char ch : str) {
        if (ch == token[0]) {
            bool match = true;
            Str::size_type i = 1;

            for (; i < token.size(); ++i) {
                if (str[i] != token[i]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                result.push_back(current);
                current = Str();
                result.push_back(token);
                continue;
            }
        }

        current += ch;
    }

    result.push_back(current);
    return result;
}
```

```
#include <vector>
#include "Str.h"

std::vector<Str> frameStrings(const std::vector<Str>& strings) {
    std::vector<Str> framedStrings;
    std::size_t maxLength = 0;

    for (const Str& str : strings) {
        if (str.size() > maxLength) {
            maxLength = str.size();
        }
    }

    Str border(maxLength + 4, '*');
    framedStrings.push_back(border);

    for (const Str& str : strings) {
        Str framedStr = "* " + str;
        framedStr += Str(maxLength - str.size(), ' ');
        framedStr += " *";
        framedStrings.push_back(framedStr);
    }

    framedStrings.push_back(border);

    return framedStrings;
}
```