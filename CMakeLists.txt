cmake_minimum_required(VERSION 3.6)
project(CODE1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        inc_me.h
        main.cpp
        MedianOfTwoSortedArrays.h
        RB.h
        blocking_ring.h
        SortList.h blocking_ring.h WordLadder1.h RemoveInvalidParenthesis.h SparseMatrixMutiply.h BinaryTreeVerticalOrderTraversal.h IntegerToEnglish.h LetterCombinationOfaPhoneNumber.h MeetingRoomII.h DecodeWays.h RegularExprMatching.h SerializeAndDeserializeBinaryTree.h NumberOfIslands.h ExpressionAddOperator.h ReverseWordsInAStringII.h MoveZeros.h BinarySearchTreeIterator.h InorderSuccessorOfBST.h AddAndSearchWord.h WordBreakI.h WordBreakII.h ValidPalindrome.h MultiplyStrings.h MinimumWindowSubstring.h Skyline.h WordSearch.h ProductOfArrayExceptSelf.h CountAndSay.h InserInterval.h SimplifyPath.h SearchInRotatedSortedArray.h ConvertSortedListToBST.h CombinationSum4.cpp CombinationSum4.h LRUCache.h TrappingRainWater.h)

add_executable(CODE1 ${SOURCE_FILES})