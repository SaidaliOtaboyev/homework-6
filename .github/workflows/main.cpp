#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int global_num;
/////////////////////////////////////////////////////////////////////////////////
int countCharOccurrences(const string &str, char ch) {
    int count = 0;
    for (char c : str) {
        if (c == ch) {
            count++;
        }
    }
    return count;
}

string findMaxCharString(const string &str1, const string &str2, char ch, int &count) {
    int count1 = countCharOccurrences(str1, ch);
    int count2 = countCharOccurrences(str2, ch);
    if (count1 == 0 && count2 == 0) {
        return "Not found";
    }
    if (count1 > count2) {
        count = count1;
        return str1;
    }
    if (count2 > count1) {
        count = count2;
        return str2;
    }
    if (count1 == count2) {
        count = count1;
        return "Same times";
    }

    return "Error"; 
}
///////////////////////////////////////////////////////////////////////////////////////////
void processString(string &str, int &digitCount) {
    digitCount = 0; 
    for (char &ch : str) {
        if (isdigit(ch)) {
            digitCount++;
        } else if (islower(ch)) {
            ch = toupper(ch);
        } else if (isupper(ch)) {
            ch = tolower(ch);
        }
    }
}
/////////////////////////////////////////////////////////////////
template <typename T>
T findLargestSum(T a, T b, T c) {
    T sum1 = a + b;
    T sum2 = a + c;
    T sum3 = b + c;
    return max({sum1, sum2, sum3});
}

template <typename T>
void findMinMax(const vector<T>& arr, T &minVal, T &maxVal) {
    if (arr.empty()) {
        throw invalid_argument("Array is empty");
    }
    minVal = *min_element(arr.begin(), arr.end());
    maxVal = *max_element(arr.begin(), arr.end());
}
///////////////////////////////////////////////////////////////////

template <typename T>
T& swapAndReturnLarger(T& a, T& b) {
    swap(a, b);
    return (a > b) ? a : b;
}

template <typename T>
void swapArrays(T* arr1, T* arr2, int size) {
    for (int i = 0; i < size; ++i) {
        swap(arr1[i], arr2[i]);
    }
}

int main() {
  cout<<"Problem 1: "<<endl;
    int local_num;
    cout << "Enter value for global variable: ";
    cin >> global_num;
    cout << "Enter value for local variable: ";
    cin >> local_num;
    int remainder = global_num % local_num;
    cout << "The remainder of " << global_num << " divided by " << local_num << " is: " << remainder << endl;
  cout<<"Problem 2: "<<endl;
  string str1, str2;
    char ch;

    // Taking input
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;
    cout << "Enter character to search for: ";
    cin >> ch;

    int count = 0;
    string result = findMaxCharString(str1, str2, ch, count);

    if (result == "Not found") {
        cout << "Not found" << endl;
    } else if (result == "Same times") {
        cout << "Same times and " << count << "." << endl;
    } else {
        cout << "The string \"" << result << "\" contains the character '" << ch << "' most times (" << count << " times)." << endl;
    }

  cout<<"Problem 3: "<<endl;
    string input;
    
    while (true) {
        cout << "Enter a string ending with 'x': ";
        cin >> input;

        if (!input.empty() && input.back() == 'x') {
            int digitCount = 0;
            processString(input, digitCount);

            cout << input << " contains " << digitCount << " digits." << endl;
            break;
        } else {
            cout << "The string does not end with 'x'. Please try again." << endl;
        }
    }
  cout<<"Problem 4: "<<endl;
  int choice;
    cout << "Enter 1 to find the pair with the largest sum, or 2 to find the min and max in an array: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "Enter three numeric values: ";
            double x, y, z;
            cin >> x >> y >> z;
            cout << "The largest sum of any pair is: " << findLargestSum(x, y, z) << endl;
            break;
        }
        case 2: {
            cout << "Enter the number of elements in the array: ";
            int n;
            cin >> n;
            vector<double> arr(n);
            cout << "Enter the elements of the array: ";
            for (int i = 0; i < n; ++i) {
                cin >> arr[i];
            }
            double minVal, maxVal;
            findMinMax(arr, minVal, maxVal);
            cout << "Min: " << minVal << " Max: " << maxVal << endl;
            break;
        }
        default: {
            cout << "Invalid choice." << endl;
            break;
        }
    }

  cout<<"Problem 5: "<<endl;
 int choice5;
    cout << "Enter 1 to swap two values and return the larger, or 2 to swap two arrays: ";
    cin >> choice5;

    switch (choice5) {
        case 1: {
            cout << "Enter two numeric values: ";
            double x, y;
            cin >> x >> y;
            double& largerValue = swapAndReturnLarger(x, y);
            cout << "After swapping: x = " << x << ", y = " << y << endl;
            cout << "The larger value is: " << largerValue << endl;
            break;
        }
        case 2: {
            cout << "Enter the number of elements in the arrays: ";
            int n;
            cin >> n;
            vector<double> arr1(n), arr2(n);
            cout << "Enter the elements of the first array: ";
            for (int i = 0; i < n; ++i) {
                cin >> arr1[i];
            }
            cout << "Enter the elements of the second array: ";
            for (int i = 0; i < n; ++i) {
                cin >> arr2[i];
            }
            swapArrays(arr1.data(), arr2.data(), n);
            cout << "After swapping:" << endl;
            cout << "First array: ";
            for (double val : arr1) {
                cout << val << " ";
            }
            cout << endl;
            cout << "Second array: ";
            for (double val : arr2) {
                cout << val << " ";
            }
            cout << endl;
            break;
        }
        default: {
            cout << "Invalid choice." << endl;
            break;
        }
    }
    return 0;
}

