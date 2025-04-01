/* Amerike university
  Author: Julio López
  Practice #: 20
  Date: 28/03/25
  Description: This program shall be a work holster of sorts where the user can write them and delete them and evfen review them */
 
  #include <iostream>
  using namespace std;
  
  const int WorkAmount = 5;
  string Work[WorkAmount];
  int MuchWork = 0;
  
  void Menu();
  void AddWork();
  void RemoveWork();
  void SeeWork();
  void Halt();
  
  int main() {
      int options;
      do {
          Menu();
          cin >> options;
          cin.clear();  
          cin.ignore(1000, '\n'); 
          
          switch (options) {
              case 1:
                  AddWork();
                  break;
              case 2:
                  RemoveWork();
                  break;
              case 3:
                  SeeWork();
                  break;
              case 4:
                  cout << "Exiting" << endl;
                  break;
              default:
                  cout << "Invalid prompt" << endl;
          }
          if (options != 4) Halt();
      } while (options != 4);
      
      return 0;
  }
  
  void Menu() {
      cout << "\n Menu" << endl;
      cout << "Add work (1)" << endl;
      cout << "Remove work (2)" << endl;
      cout << "View work (3)" << endl;
      cout << "Exit (4)" << endl;
      cout << "Type the corresponding number: ";
  }
  
  void AddWork() {
      if (MuchWork >= WorkAmount) {
          cout << "Cannot add more work, work limit is: " << WorkAmount << endl;
          return;
      }
      cout << "Add new work: ";
      getline(cin, Work[MuchWork]);
      MuchWork++;
      cout << "Work added to the list, press 3 to view" << endl;
  }
  
  void RemoveWork() {
      if (MuchWork == 0) {
          cout << "Nothing to delete" << endl;
          return;
      }
      
      SeeWork();
      int index;
      cout << "Choose the corresponding number to delete: ";
      cin >> index;
      cin.clear();  
      cin.ignore(1000, '\n');  
      
      if (index < 1 || index > MuchWork) {
          cout << "Invalid index" << endl;
          return;
      }
      
      for (int i = index - 1; i < MuchWork - 1; i++) {
          Work[i] = Work[i + 1];
      }
      MuchWork--;
      cout << "Work deleted" << endl;
  }
  
  void SeeWork() {
      if (MuchWork == 0) {
          cout << "Nothing to see here yet" << endl;
          return;
      }
      cout << "\nWork list" << endl;
      for (int i = 0; i < MuchWork; i++) {
          cout << i + 1 << ". " << Work[i] << endl;
      }
  }
  
  void Halt() {
      cout << "\nPress ENTER to continue ";
      cin.get();
  }
  
 