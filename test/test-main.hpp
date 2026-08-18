// SPDX-FileCopyrightText: 2026 Maarten L. Hekkelman
//
// SPDX-License-Identifier: BSL-1.0

#ifndef GXRIO_TEST_MAIN_HPP
#define GXRIO_TEST_MAIN_HPP

#define CATCH_CONFIG_RUNNER
#include <catch2/catch_all.hpp>

#include <filesystem>
#include <string>

namespace fs = std::filesystem;

/// \brief The directory that contains the test data files
inline fs::path gTestDir;

/// \brief Shared main for all test executables
///
/// Adds a --testdir command line option that overrides the automatic
/// detection of the test data directory.
inline int gxrio_test_main(int argc, char *argv[])
{
	Catch::Session session;

	std::string testdir;

	using namespace Catch::Clara;
	auto cli = session.cli()
		| Opt(testdir, "dir")["--testdir"]("Directory containing the test data files");

	session.cli(cli);

	if (int rc = session.applyCommandLine(argc, argv); rc != 0)
		return rc;

	if (not testdir.empty())
		gTestDir = testdir;
	else if (fs::current_path().filename().string() == "Debug" or fs::current_path().filename().string() == "Release")
		gTestDir = fs::current_path().parent_path().parent_path() / "test";
	else
		gTestDir = fs::current_path();

	return session.run();
}

#endif
