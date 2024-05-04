[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- ABOUT THE PROJECT -->
## About The Project

This program written in C++ implements binary search trees and balanced binary trees with functions like: Insertion, Search and Inorder and By Levels traversal.

A degree 2 tree is called a binary tree (AB).

An AB is balanced if the difference in the sizes of its two subtrees is at most
one. A binary tree is perfectly balanced if all its branches are balanced.

A binary search tree (ABB) is an AB in which the value of the root of each
branch is:

&emsp;● Greater than the values ​​of the nodes in its left subtree.

&emsp;● Less than the values ​​of the nodes in its right subtree.

![ABB](Binary_search_tree_example.gif)

An abstract generic data type AB<Key> is developed to represent any tree
binary containing values ​​of type key, Key. From AB<Key> the data types are derived
generics ABE<Key> and ABB<Key>. The implementation of the generic type allows the following operations:

&emsp;● Search: Checks if a given key is found in the tree.

&emsp;● Insert: A new key is added to the tree.

&emsp;● Traverse: All the nodes of the tree are traversed. According to the order established in the route

We can find, among others, the following:

&emsp;&emsp;○ Inorder: It is traversed in order: left subtree - root - right subtree

&emsp;&emsp;○ By levels: The nodes of the different levels of the tree are traversed in order growing from the root and within each level from left to &emsp;right.

The main program accepts the following command line options:

-ab <abe|abb>, to indicate the type of tree to work with.

-init [i] [s][f], indicates how to enter the sequence data

i=manual

i=random [s], s is the number of elements to generate

i=file [s][f], s is the number of elements to generate, f is name of the input file



<p align="right">(<a href="#readme-top">back to top</a>)</p>



### Built With


* ![C++][C++.js]

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

### Prerequisites

None

### Installation

No installation required :)

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- USAGE EXAMPLES -->
## Usage

1. Download the files
2. Compile with g++
```
g++ bigint_main.cc bigint_func.cc
```
4. All ready!

<p align="right">(<a href="#readme-top">back to top</a>)</p>




<!-- LICENSE -->
## License

Distributed under the MIT License.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Joel Óscar - josc.margut@gmail.com

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/github_username/repo_name.svg?style=for-the-badge
[contributors-url]: https://github.com/github_username/repo_name/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/github_username/repo_name.svg?style=for-the-badge
[forks-url]: https://github.com/github_username/repo_name/network/members
[stars-shield]: https://img.shields.io/github/stars/github_username/repo_name.svg?style=for-the-badge
[stars-url]: https://github.com/github_username/repo_name/stargazers
[issues-shield]: https://img.shields.io/github/issues/github_username/repo_name.svg?style=for-the-badge
[issues-url]: https://github.com/github_username/repo_name/issues
[license-shield]: https://img.shields.io/github/license/github_username/repo_name.svg?style=for-the-badge
[license-url]: https://github.com/github_username/repo_name/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/joel-%C3%B3scar-mart%C3%ADn-guti%C3%A9rrez-578ab8303
[product-screenshot]: images/screenshot.png
[Next.js]: https://img.shields.io/badge/next.js-000000?style=for-the-badge&logo=nextdotjs&logoColor=white
[Next-url]: https://nextjs.org/
[C++.js]: https://img.shields.io/badge/-C++-blue?logo=cplusplus
[React.js]: https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB
[React-url]: https://reactjs.org/
[Vue.js]: https://img.shields.io/badge/Vue.js-35495E?style=for-the-badge&logo=vuedotjs&logoColor=4FC08D
[Vue-url]: https://vuejs.org/
[Angular.io]: https://img.shields.io/badge/Angular-DD0031?style=for-the-badge&logo=angular&logoColor=white
[Angular-url]: https://angular.io/
[Svelte.dev]: https://img.shields.io/badge/Svelte-4A4A55?style=for-the-badge&logo=svelte&logoColor=FF3E00
[Svelte-url]: https://svelte.dev/
[Laravel.com]: https://img.shields.io/badge/Laravel-FF2D20?style=for-the-badge&logo=laravel&logoColor=white
[Laravel-url]: https://laravel.com
[Bootstrap.com]: https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white
[Bootstrap-url]: https://getbootstrap.com
[JQuery.com]: https://img.shields.io/badge/jQuery-0769AD?style=for-the-badge&logo=jquery&logoColor=white
[JQuery-url]: https://jquery.com 
