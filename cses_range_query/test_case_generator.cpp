// // #include <bits/stdc++.h>
// // #define int long long
// // using namespace std;

// // int32_t main(){
// //     int t = 1;
// //     while(t--){

// //         string s = "h t t p s : / / l e e t c o d e . c a / 2 0 1 6 - 0 6 - 2 7 - 2 1 0 - C o u r s e - S c h e d u l e - I I /";
// //         string ns ;
// //         for(char c : s){
// //             if(c != ' '){
// //                 ns += c;
// //             }
// //         }
// //         cout<<ns<<endl;







// //     }
// //     return 0;
// // }


// #include <iostream>
// #include <vector>
// #include <string>
// #include <unordered_set>
// using namespace std;

// struct Directory {
//     int id;
//     string name;
//     vector<Directory*> subdirectories;
// };

// void findDirectoriesWithSameNameParent(Directory* dir, unordered_set<string>& parentNames, vector<int>& result) {
//     // If the directory name is already in the parent names set, add its id to the result
//     if (parentNames.count(dir->name)) {
//         result.push_back(dir->id);
//     }
    
//     // Add current directory name to the set of parent names
//     parentNames.insert(dir->name);
    
//     // Recur for all subdirectories
//     for (auto subDir : dir->subdirectories) {
//         findDirectoriesWithSameNameParent(subDir, parentNames, result);
//     }
    
//     // Remove current directory name from the set before returning to the parent call
//     parentNames.erase(dir->name);
// }

// vector<int> getDirectoriesWithSameNameParent(Directory* root) {
//     vector<int> result;
//     unordered_set<string> parentNames;
//     findDirectoriesWithSameNameParent(root, parentNames, result);
//     return result;
// }

// int main() {
//     // Example usage
//     Directory* dir1 = new Directory{1, "kevin", {}};
//     Directory* dir2 = new Directory{2, "stuff", {}};
//     Directory* dir3 = new Directory{3, "kevin", {}};

//     dir1->subdirectories.push_back(dir2);
//     dir2->subdirectories.push_back(dir3);

//     vector<int> result = getDirectoriesWithSameNameParent(dir1);

//     for (int id : result) {
//         cout << id << endl;
//     }

//     // Clean up memory
//     delete dir3;
//     delete dir2;
//     delete dir1;

//     return 0;
// }


#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

struct Directory {
    int id;
    std::string name;
    std::vector<Directory*> subdirectories;

    Directory(int id, std::string name) : id(id), name(std::move(name)) {}
};

// Helper function to perform a depth-first search (DFS) and find directories with a parent of the same name
void findDirectoriesWithSameNameAncestor(Directory* dir, std::unordered_set<std::string>& ancestors, std::vector<int>& result) {
    if (dir == nullptr) {
        return;
    }

    // Check if the current directory's name is in the ancestor set
    if (ancestors.find(dir->name) != ancestors.end()) {
        result.push_back(dir->id);
    }

    // Add the current directory's name to the set of ancestors
    ancestors.insert(dir->name);

    // Recursively check all subdirectories
    for (auto* subdirectory : dir->subdirectories) {
        findDirectoriesWithSameNameAncestor(subdirectory, ancestors, result);
    }

    // Remove the current directory's name from the set of ancestors (backtracking)
    ancestors.erase(dir->name);
}

std::vector<int> listDirectoriesWithSameNameAncestor(Directory* root) {
    std::unordered_set<std::string> ancestors;
    std::vector<int> result;
    findDirectoriesWithSameNameAncestor(root, ancestors, result);
    return result;
}

int main() {
    // Create a sample directory tree
    Directory* root = new Directory(1, "home");
    Directory* sub1 = new Directory(2, "kevin");
    Directory* sub2 = new Directory(3, "stuff");
    Directory* sub3 = new Directory(4, "kevin");  // Same name as an ancestor
    Directory* sub4 = new Directory(5, "docs");

    root->subdirectories.push_back(sub1);
    root->subdirectories.push_back(sub2);
    sub2->subdirectories.push_back(sub3);
    sub3->subdirectories.push_back(sub4);

    // Find directories with a parent of the same name
    std::vector<int> result = listDirectoriesWithSameNameAncestor(root);

    // Print the unique identifiers of the directories
    std::cout << "Directories with a parent of the same name have IDs: ";
    for (int id : result) {
        std::cout << id << " ";
    }
    std::cout << std::endl;

    // Clean up dynamically allocated memory
    delete root;
    delete sub1;
    delete sub2;
    delete sub3;
    delete sub4;

    return 0;
}


