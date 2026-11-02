Aim
To design and implement an efficient algorithm that formats an array of words into fully justified text, where each line contains exactly maxWidth characters.

Objectives
- To apply greedy line-packing and string simulation techniques for text formatting problems.

- To efficiently distribute spaces between words so each line is exactly maxWidth characters wide.

- To handle edge cases such as single-word lines and the last line, which are left-justified.

- To analyze time and space complexity of the solution.

- To validate the solution using test cases and edge cases.

Hardware Requirement
Standard desktop/laptop with minimum 4 GB RAM, dual-core processor, and keyboard/mouse.

Software Requirement
- Operating System: Windows / Linux / macOS

- C++ Compiler: GCC/Clang

- Java Development Kit (JDK 8 or above)

- IDE: VS Code / Code::Blocks / IntelliJ / Eclipse

Description of Program
The program uses a greedy approach to pack as many words as possible into each line without exceeding maxWidth. For each line, the total number of spaces needed is computed and distributed as evenly as possible between the words. When the spaces cannot be divided evenly, the extra spaces are assigned to the leftmost gaps first. The last line, as well as any line containing only a single word, is left-justified with a single space between words and trailing spaces padded to reach maxWidth.

C++ Code
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int i = 0, n = words.size();
    while (i < n) {
        int lineLen = words[i].size(), j = i + 1;
        // Fit as many words as possible on this line
        while (j < n && lineLen + 1 + (int)words[j].size() <= maxWidth)
            lineLen += 1 + words[j++].size();
        int numWords = j - i;
        int totalSpaces = maxWidth - (lineLen - (numWords - 1));
        string line = words[i];
        if (numWords == 1 || j == n) {
            // Last line or single word: left-justify
            for (int k = i + 1; k < j; k++)
                line += " " + words[k];
            line += string(maxWidth - line.size(), ' ');
        } else {
            // Distribute spaces evenly
            int spaceEach = totalSpaces / (numWords - 1);
            int extra     = totalSpaces % (numWords - 1);
            for (int k = i + 1; k < j; k++) {
                int sp = spaceEach + (k - i <= extra ? 1 : 0);
                line += string(sp, ' ') + words[k];
            }
        }
        result.push_back(line);
        i = j;
    }
    return result;
}

int main() {
    int n, maxWidth;
    cin >> n;
    vector<string> words( n );
    for (int i = 0; i < n; i++) cin >> words[i];
    cin >> maxWidth;
    for (const string& line : fullJustify(words, maxWidth))
        cout << "\"" << line << "\"\n";
}

Java Code
import java.util.*;
public class TextJustification {
    public static List<String> fullJustify(String[] words, int maxWidth) {
        List<String> result = new ArrayList<>();
        int i = 0, n = words.length;
        while (i < n) {
            int lineLen = words[i].length(), j = i + 1;
            // Fit as many words as possible
            while (j < n && lineLen + 1 + words[j].length() <= maxWidth)
                lineLen += 1 + words[j++].length();
            int numWords = j - i;
            int totalSpaces = maxWidth - (lineLen - (numWords - 1));
            StringBuilder sb = new StringBuilder(words[i]);
            if (numWords == 1 || j == n) {
                // Last line or single word: left-justify
                for (int k = i + 1; k < j; k++)
                    sb.append(" ").append(words[k]);
                while (sb.length() < maxWidth) sb.append(" ");
            } else {
                int spaceEach = totalSpaces / (numWords - 1);
                int extra     = totalSpaces % (numWords - 1);
                for (int k = i + 1; k < j; k++) {
                    int sp = spaceEach + (k - i <= extra ? 1 : 0);
                    for (int s = 0; s < sp; s++) sb.append(" ");
                    sb.append(words[k]);
                }
            }
            result.add(sb.toString());
            i = j;
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] words = new String[n];
        for (int i = 0; i < n; i++) words[i] = sc.next();
        int maxWidth = sc.nextInt();
        for (String line : fullJustify(words, maxWidth))
            System.out.println("\"" + line + "\"");
    }
}

Input / Output Examples
Input

Output

words = ["This","is","an","example","of","text","justification"] maxWidth = 16

"This    is    an" "example  of text" "justification  "

words = ["What","must","be","acknowledgment","shall","be"] maxWidth = 16

"What   must  be" "acknowledgment  " "shall be        "

words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer"] maxWidth = 20

"Science  is  what we" "understand      well" "enough to explain to" "a computer          "

 

. give code
