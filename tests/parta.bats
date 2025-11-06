#!/usr/bin/env bats
load 'test_helpers'


setup() {
    export BATS_TEST_TIMEOUT=10
}

@test "parta with single argument 'Hello'" {
    run parta Hello
    assert_output "HELLO"
    assert_success
}

@test "parta with single argument 'HowDY'" {
    run parta HowDY
    assert_output "HOWDY"
    assert_success
}

@test "parta with single argument 'Goodbye'" {
    run parta Goodbye
    assert_output "GOODBYE"
    assert_success
}

@test "parta with multiple arguments 'Hello Goodbye'" {
    run parta Hello Goodbye
    assert_output "HELLO,GOODBYE"
    assert_success
}

@test "parta with multiple arguments 'A B C D E F'" {
    run parta A B C D E F
    assert_output "A,B,C,D,E,F"
    assert_success
}

@test "parta with no arguments" {
    run parta
    assert_output "ERROR: No arguments"
    assert_failure
}