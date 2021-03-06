[![Licence](https://img.shields.io/badge/license-GPL_3-green.svg?dummy)](https://raw.githubusercontent.com/DomainDrivenConsulting/dogen/master/LICENCE)
[![Build Status](https://img.shields.io/travis/DomainDrivenConsulting/dogen.svg?label=linux/osx)](https://travis-ci.org/DomainDrivenConsulting/dogen)
[![Build Status](https://img.shields.io/appveyor/ci/mcraveiro/dogen.svg?label=windows)](https://ci.appveyor.com/project/mcraveiro/dogen)
[![Coverage Status](https://img.shields.io/coveralls/DomainDrivenConsulting/dogen.svg)](https://coveralls.io/r/DomainDrivenConsulting/dogen)
[![Issues](https://img.shields.io/github/issues/domaindrivenconsulting/dogen.svg)](https://github.com/DomainDrivenConsulting/dogen/issues)
[![Releases](https://badge.fury.io/gh/domaindrivenconsulting%2fdogen.svg)](https://github.com/domaindrivenconsulting/dogen/releases)
[![Gitter](https://badges.gitter.im/join chat.svg)](https://gitter.im/domaindrivenconsulting/dogen?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)
[![Coverity](https://img.shields.io/coverity/scan/9268.svg)](https://scan.coverity.com/projects/domaindrivenconsulting-dogen)
[![Build Time](https://buildtimetrend.herokuapp.com/badge/DomainDrivenConsulting/dogen/latest)](https://buildtimetrend.herokuapp.com/dashboard/DomainDrivenConsulting/dogen)

# Dogen

## Overview

**Dogen** is a code generator designed to target domain models, inspired
by the
[Domain Driven Design](http://en.wikipedia.org/wiki/domain-driven_design)
methodology. our main objective is to automate the modeling process as
much as possible: the user creates domain models using a supported uml
tool and respecting a set of predefined restrictions; dogen then uses
the tool's diagram files to generate the source code
representation. the generated code contains most of the services
required from a typical c++ domain object such as serialisation,
hashing, streaming and so on.

Please note that **the code generated by dogen is C++-11 only.**

## Useful links

- Git repository: [GitHub](https://github.com/domaindrivenconsulting/dogen), [BitBucket](https://bitbucket.org/marco_craveiro/dogen/overview) (mirror).
- Continuous Integration: [Travis](https://travis-ci.org/DomainDrivenConsulting/dogen/builds).
- [Sprint Backlogs](https://github.com/domaindrivenconsulting/dogen/tree/master/doc/agile).
- [Demo](https://youtu.be/Z7k8qbImXkU): quite a few sprints old, but largely applicable.

## Obtaining Dogen

Please see section
[Obtaining Dogen](https://github.com/DomainDrivenConsulting/dogen/blob/master/doc/manual/manual.tex)
for instructions on how to install binary packages or compile from
source.
