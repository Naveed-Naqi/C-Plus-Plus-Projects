#include<iostream>
#include<unistd.h>
#include <sys/types.h>
using namespace std;

int main() {
  pid_t pid;
  pid = fork();
  if (pid > 0) {
    cout << "I am a parent\n";
  } else if (pid == 0) { 
    cout << "I am a child\n";
  }
  return 0;
}