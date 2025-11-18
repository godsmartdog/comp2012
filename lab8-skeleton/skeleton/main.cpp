#include <iostream>
#include "Song.h"
#include "BST.h"

int main() {
    int testID;
    std::cout << "Enter test ID: ";
    std::cin >> testID;

    if (testID == 1) {
        // Tree in an upside-down V shape
        int (*funcs[])(const Song&, const Song&) = {compare_by_length, compare_by_name, compare_by_artist};
        BST bst(funcs, 3);

        Song song1(241, "All I Want for Christmas is You", "Mariah Carey");
        Song song2(263, "Last Christmas", "Wham!");
        Song song3(268, "The Prayer", "Celine Dion");
        Song song4(182, "White Christmas", "Bing Crosby");
        Song song5(166, "Have Yourself a Merry Little Christmas", "Judy Garland");

        for (const Song &song : {song1, song2, song3, song4, song5})
            bst.insert(song);

        std::cout << "\n====== Using print_in_order() ======\n";
        bst.print_in_order();

        std::cout << "\n====== Using print_nth() ======\n";
        bst.print_nth(1);
        bst.print_nth(2);
        bst.print_nth(3);
        bst.print_nth(4);
        bst.print_nth(5);
    } else if (testID == 2) {
        // Tree in a diamond-ish shape + tie-breaker
        int (*funcs[])(const Song&, const Song&) = {compare_by_name, compare_by_length, compare_by_artist};
        BST bst(funcs, 3);

        Song song1(241, "All I Want for Christmas is You", "My Chemical Romance");
        Song song2(241, "All I Want for Christmas is You", "Michael Buble");
        Song song3(241, "All I Want for Christmas is You", "Pentatonix");
        Song song4(241, "All I Want for Christmas is You", "Mariah Carey");
        Song song5(241, "All I Want for Christmas is You", "Kelly Clarkson");

        for (const Song &song : {song1, song2, song3, song4, song5})
            bst.insert(song);

        std::cout << "\n====== Using print_in_order() ======\n";
        bst.print_in_order();

        std::cout << "\n====== Using print_nth() ======\n";
        bst.print_nth(1);
        bst.print_nth(2);
        bst.print_nth(3);
        bst.print_nth(4);
        bst.print_nth(5);
    } else if (testID == 3) {
        // More songs!
        int (*funcs[])(const Song&, const Song&) = {compare_by_name, compare_by_artist, compare_by_length};
        BST bst(funcs, 3);

        Song song1(151, "It's the Most Wonderful Time of the Year", "Andy Williams");
        Song song2(182, "Feliz Navidad", "Jose Feliciano");
        Song song3(126, "Rockin' around the Christmas Tree", "Brenda Lee");
        Song song4(185, "Let It Snow! Let It Snow! Let It Snow!", "Vaughn Monroe");
        Song song5(186, "Rudolph, the Red-Nosed Reindeer", "Gene Autry");
        Song song6(208, "Do You Want to Build a Snowman?", "Kristen Bell");
        Song song7(247, "Where Are You Christmas?", "Faith Hill");
        Song song8(208, "Jingle Bell Rock", "Bobby Helms");
        Song song9(208, "Mary, Did You Know?", "Pentatonix");

        for (const Song &song : {song1, song2, song3, song4, song5, song6, song7, song8, song9})
            bst.insert(song);
        
        std::cout << "\n====== Using print_in_order() ======\n";
        bst.print_in_order();

        BST bst2(bst);
        std::cout << "\n====== Copied BST ======\n";
        bst2.print_in_order();
    }

    return 0;
}
