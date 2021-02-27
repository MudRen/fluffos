inherit "/inherit/tests";

int func() {
  return 1;
}

int func1(string moo, mixed args...) {
  func();
  return 1;
}

void do_tests()
{
  ASSERT_EQ(
    ({ /* sizeof() == 5 */
      "describe_test",
      "query_test_info",
      "do_tests",
      "func1",
      "func",
    }), functions(this_object(), 0));
  ASSERT_EQ(
    ({ /* sizeof() == 5 */
      ({ /* sizeof() == 4 */
        "describe_test",
        1,
        "void",
        "string"
      }),
      ({ /* sizeof() == 3 */
        "query_test_info",
        0,
        "string"
      }),
      ({ /* sizeof() == 3 */
        "do_tests",
        0,
        "void"
      }),
      ({ /* sizeof() == 5 */
        "func1",
        2,
        "int",
        "string",
        "mixed"
      }),
      ({ /* sizeof() == 3 */
        "func",
        0,
        "int"
      })
    }), functions(this_object(), 1));
  ASSERT_EQ(
    ({ /* sizeof() == 3 */
      "do_tests",
      "func1",
      "func"
    }), functions(this_object(), 2));
  ASSERT_EQ(
    ({ /* sizeof() == 3 */
      ({ /* sizeof() == 3 */
        "do_tests",
        0,
        "void"
      }),
          ({ /* sizeof() == 5 */
            "func1",
            2,
            "int",
            "string",
            "mixed"
          }),
          ({ /* sizeof() == 3 */
            "func",
            0,
            "int"
          })
    }), functions(this_object(), 3));
}
