#include <iostream>
#include <sstream>
#include "linkedlist.hpp"
using namespace std;

bool RunListTests(LinkedList& a);
bool RunIndividualTest(string desiredOutput, string actualOutput, string testLabel, string testId);
void RunLab09Tests();
void Double(int& i);

void Double(int& i) {
    i *= 2;
}

int main( ) {
   LinkedList a;

   cout << "*** List tests on original list: "
        << (RunListTests(a) ? "ALL passed" : "Some failed") << endl;


   // TEST 8: COPY CONSTRUCTOR
   LinkedList b(a);
   b.DeleteFirst();
   cout << "*** List tests on version created with copy constructor: "
        << (RunListTests(b) ? "TEST PASSED: 8" : "TEST FAILED: 8") << endl;

   // TEST 9: EQUALITY COMPARISON
   cout << "Testing equality comparison operator: "
        << (a == b ? "9a passed" : "9a failed") << endl;
   b.InsertLast(1); // add a new element to b
   cout << "Retesting after modifying 1 array: "
        << (a == b ? "9b failed" : "9b passed") << endl;

   // TEST 10: ASSIGNMENT OPERATOR
   b = b; // make sure this doesn't break
   cout << "Testing assignment operator on self-assignment: "
        << (b == b ? "10a passed" : "10a failed") << endl;
   a = b;
   cout << "Testing assignment operator: "
        << (a == b ? "10b passed" : "10b failed") << endl;

   RunLab09Tests();
   return 0;
}

void RunLab09Tests() {
    LinkedList a;
    for (int i = 0; i < 15; i++) a.InsertFirst(200 + i);

    LinkedList b = a; //Make a copy of a and store into b
    cout << "Is 200 in the list? " << a.exists(200) << endl;
    a.apply(Double);
    cout << "How about now? " << a.exists(200) << endl;
    cout << a << endl;
    cout << "Adding LinkedLists a and b gives:\n" << a + b << endl;

    a.clear();
    cout << a << endl << "Reached end!";

}

bool RunIndividualTest(string desiredOutput, string actualOutput, string testLabel, string testId) {
    if (desiredOutput != actualOutput) {
        cout << "TEST FAILED: " << testLabel << endl;
        return false;
    }
    cout << "TEST PASSED: " << testId << endl;
    return true;
}

/* Run individual insert, delete, etc. tests */
bool RunListTests(LinkedList& a){
   stringstream testoutput;
   bool pass = true;

   // TEST 1: Print contents and size of empty list
  testoutput << a;
   pass &= RunIndividualTest("", testoutput.str(), "Print empty array", "1a");
   pass &= RunIndividualTest("0", to_string(a.Size()), "Size of empty array", "1b");
    testoutput.str("");
    a.PrintBackwards(testoutput);
    pass &= RunIndividualTest("", testoutput.str(), "Print empty array backwards", "1c");

     // TEST 2: Pre-pend 110 through 1R0 to a (11 elements total)
     testoutput.str(""); // Reset test output string
     for (int i = 110; i >= 100; i--) {
        pass &= a.InsertFirst(i);
     }
     testoutput << a;
     pass &= RunIndividualTest("100 101 102 103 104 105 106 107 108 109 110 ",
        testoutput.str(), "InsertFirst: 110 through 100", "2a");
     pass &= RunIndividualTest("11", to_string(a.Size()),
         "Size after adding 11 elements to empty array", "2b");

    testoutput.str("");
    a.PrintBackwards(testoutput);
    pass &= RunIndividualTest("110 109 108 107 106 105 104 103 102 101 100 ",
            testoutput.str(), "InsertFirst: Backwards traversal", "2c");


   // TEST 3: Append 111 through 120 (21 elements total):
   testoutput.str(""); // Reset test output string
   for (int i = 111; i < 121; i++) {
      pass &= a.InsertLast(i);
   }
   testoutput << a;
   pass &= RunIndividualTest(
      "100 101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 ",
      testoutput.str(), "InsertLast: 111 through 120", "3a");
   pass &= RunIndividualTest("21", to_string(a.Size()),
      "Size after adding 10 elements to 11-element array", "3b");

    testoutput.str("");
    a.PrintBackwards(testoutput);
    pass &= RunIndividualTest("120 119 118 117 116 115 114 113 112 111 110 109 108 107 106 105 104 103 102 101 100 ",
            testoutput.str(), "InsertLast: Backwards traversal", "3c");


      // TEST 4: DeleteFirst 10 elements
      testoutput.str("");
      for (int i = 0; i < 10; i++) {
          pass &= a.DeleteFirst();
      }
      testoutput << a;
      pass &= RunIndividualTest(
         "110 111 112 113 114 115 116 117 118 119 120 ",
         testoutput.str(), "After DeleteFirst 10 elements", "4a");
      pass &= RunIndividualTest("11", to_string(a.Size()), "Size after deleting 1st 10 elements", "4b");

      testoutput.str("");
    a.PrintBackwards(testoutput);
    pass &= RunIndividualTest("120 119 118 117 116 115 114 113 112 111 110 ", testoutput.str(),
            "InsertLast: Backwards traversal", "4c");

  // TEST 5: DeleteLast 11 elements
   testoutput.str("");
   for (int i = 0; i < 10; i++) {
       pass &= a.DeleteLast();
   }
   testoutput << a;
   pass &= RunIndividualTest("110 ", testoutput.str(), "After DeleteLast 10 elements", "5a");
   pass &= RunIndividualTest("1", to_string(a.Size()), "Size after deleting 10 elements", "5b");

    testoutput.str("");
    a.PrintBackwards(testoutput);
    pass &= RunIndividualTest("110 ", testoutput.str(), "DeleteLast: Backwards traversal", "5c");

   testoutput.str("");
   pass &= a.DeleteLast();
   testoutput << a;
   pass &= RunIndividualTest("", testoutput.str(), "After DeleteLast remaining element", "5d");
   pass &= RunIndividualTest("0", to_string(a.Size()), "Size after deleting all elements", "5e");

    // TEST 6: Try to delete nonexistent element
   pass &= RunIndividualTest("0", to_string(a.DeleteFirst()), "DeleteFirst on empty list", "6a");
   pass &= RunIndividualTest("0", to_string(a.DeleteLast()), "DeleteLast on empty list", "6b");
   pass &= RunIndividualTest("0", to_string(a.Size()), "Size after deletes on empty list", "6c");

   // TEST 7: Use InsertLast to add one value back in
   testoutput.str(""); // Reset test output string
   a.InsertLast(152);
   testoutput << a;
   pass &= RunIndividualTest("152 ", testoutput.str(), "Final InsertLast on empty list", "7a");
   pass &= RunIndividualTest("1", to_string(a.Size()), "Size after final InsertLast", "7b");

    testoutput.str("");
    a.PrintBackwards(testoutput);
    pass &= RunIndividualTest("152 ", testoutput.str(), "Final InsertLast: Backwards traversal", "7c");

   return pass;
}

