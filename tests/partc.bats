#!/usr/bin/env bats
load 'test_helpers'

setup() {
    export BATS_TEST_TIMEOUT=10
}


@test "partc fox tests/file1.txt" {
    run partc fox tests/file1.txt
    assert_output "FOUND: fox"
    assert [ "$status" -eq 0 ]                             # Assert if exit status matches
}

@test "partc deer tests/file1.txt" {
    run partc deer tests/file1.txt
    assert_output "NOT FOUND: deer"
    assert [ "$status" -eq 0 ]                             # Assert if exit status matches
}

@test "partc grass tests/file2.txt" {
    run partc grass tests/file2.txt
    assert_output "FOUND: grass"
    assert [ "$status" -eq 0 ]                             # Assert if exit status matches
}

@test "partc tree tests/file2.txt" {
    run partc tree tests/file2.txt
    assert_output "NOT FOUND: tree"
    assert [ "$status" -eq 0 ]                             # Assert if exit status matches
}

@test "partc fox tests/no_such_file.txt" {
    run partc fox tests/no_such_file.txt
    assert_output "ERROR: tests/no_such_file.txt doesn't exist"
    assert [ "$status" -eq 2 ]                              # Assert if exit status was 2
}
@test "partc fox tests/non_existant.txt" {
    run partc fox tests/non_existant.txt
    assert_output "ERROR: tests/non_existant.txt doesn't exist"
    assert [ "$status" -eq 2 ]                              # Assert if exit status was 2
}
@test "partc" {
    run partc

    assert_output "ERROR: No arguments"                    # Assert if output matches
    assert [ "$status" -eq 1 ]                             # Assert if exit status matches
}
