# knpwrs is Learning C++

I am working through the books [Professional C++, Third Edition] and [Effective
Modern C++]. Beyond what the books cover, I am also going to be using [CLion],
[CMake], [Travis], and [Google Test] along my educational journey.

## Background

C++ was actually the first "real" language I learned back in High School. I
never got into the really advanced topics, however, and I started using Java as
my primary language in college before moving on to Scala and then JavaScript.
One of my friends has been raving about how awesome C++14 is, and I am
interested in gaining a better understanding of native node.js modules so I
decided to give learning *modern* C++ a go.

## Reflections (So Far)

* The lack of any sort of de facto dependency management tool (to the best of my
  Google-fu) is somewhat frustrating. Cmake has [`ExternalProject`] which feels
  heavy, though I understand why. Then there's [Biicode] but now on separate
  occasions weeks apart their website / download doesn't work (for me) and I
  can't find anything on [Homebrew]. I've seen various other small projects
  which appear to be unmaintained. Installing dependencies globally is an
  option, however this is [not recommended for certain libraries][gtestfaq].
  Without some sort of solution to change global environments on a
  project-by-project basis (e.g., [rvm] or [virtualenv], to the best of my
  understanding) this can become somewhat problematic. My current solution is to
  use [git subtrees].
* Reconciling the differences between compilers of different systems (e.g., my
  local machine and [Travis]) has proven to be more problematic than I'd like.
  One solution I found that works well for the purpose of CI / testing is to use
  [Docker] with a lightweight base image such as [Alpine]. While this works well
  for CI / testing I believe it will actually become even more problematic for
  cross-platform applications.

## License

Most of the code will be out of the books with possibly a few modifications here
and there. See the book licenses for license information regarding the code in
this repository.

[`ExternalProject`]: https://cmake.org/cmake/help/v3.2/module/ExternalProject.html "CMake External Project"
[Alpine]: http://www.alpinelinux.org/ "Alpine Linux"
[Biicode]: https://www.biicode.com/ "Biicode Dependency Manager"
[CLion]: https://www.jetbrains.com/clion/ "CLion"
[CMake]: https://cmake.org/ "CMake"
[Docker]: https://www.docker.com/ "Docker"
[Effective Modern C++]: http://shop.oreilly.com/product/0636920033707.do?cmp=af-code-books-video-product_cj_0636920033707_7708709 "Effective Modern C++"
[git subtrees]: https://medium.com/@v/git-subtrees-a-tutorial-6ff568381844#.e2payrroy "git subtrees: a tutorial"
[Google Test]: https://github.com/google/googletest "Google Test"
[gtestfaq]: https://github.com/google/googletest/blob/d225acc90bc3a8c420a9bcd1f033033c1ccd7fe0/googletest/docs/FAQ.md#why-is-it-not-recommended-to-install-a-pre-compiled-copy-of-google-test-for-example-into-usrlocal "Why is it not recommended to install a pre-compiled copy of Google Test (for example, into /usr/local)?"
[Homebrew]: http://brew.sh "Homebrew Package Manager for Mac"
[Professional C++, Third Edition]: http://www.wrox.com/WileyCDA/WroxTitle/Professional-C-3rd-Edition.productCd-1118858050.html "Professional C++, Third Edition"
[rvm]: https://rvm.io/ "Ruby Version Manager"
[Travis]: https://docs.travis-ci.com/user/languages/cpp "Building a C++ Project on Travis"
[virtualenv]: https://virtualenv.pypa.io/en/latest/ "Virtual Environments"
