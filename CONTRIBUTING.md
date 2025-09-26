# Contributing

This repository follows a simple fork-and-pull-request workflow. Use the guidelines below so your change can be reviewed and merged quickly.

## Editing an existing file
1. Fork the repository on GitHub.
2. Clone your fork:
    - git clone git@github.com:<your-username>/<repo>.git
    - cd <repo>
    - git remote add upstream git@github.com:osalotioman/utils.git
3. Create a topic branch:
    - git checkout -b feat/short-descriptive-name
4. Make small, focused changes. Run the project’s tests and linters locally (e.g., npm test, pytest, black, eslint) and fix any issues.
5. Commit with a clear message:
    - git add .
    - git commit -m "Short: describe what this change does"
    - If relevant, reference an issue: "Fixes #123"
6. Push your branch and open a Pull Request against the repository’s default branch:
    - git push origin feat/short-descriptive-name
    - On GitHub, open a PR and include: purpose, what you changed, how to test, and screenshots if applicable.

## Adding new files or programs
- Add a short README or usage note for the new file/program.
- Include tests or example usage demonstrating the feature.
- Add a license header if the project requires one.
- Follow the same branch → commit → push → PR flow above and describe how to build/run the new program in the PR.

## General guidelines
- Keep changes atomic and focused.
- Follow the repository’s coding style and formatting tools.
- Update documentation and tests for behavioral changes.
- Mention any backwards-incompatible changes clearly in the PR.
- Be responsive to review feedback and update your branch as requested.

Thanks — clear, tested, and well-documented contributions make reviews faster and increase the chance of merging.
