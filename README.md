# Ledger DigitalBits App

[![Compilation & tests](https://github.com/xdbfoundation/app-digitalbits/actions/workflows/ci-workflow.yml/badge.svg?branch=develop)](https://github.com/xdbfoundation/app-digitalbits/actions/workflows/ci-workflow.yml)
<!-- [![Swap function tests](https://github.com/LedgerHQ/app-stellar/actions/workflows/swap-ci-workflow.yml/badge.svg?branch=develop)](https://github.com/LedgerHQ/app-stellar/actions/workflows/swap-ci-workflow.yml) -->

## Introduction

This is the wallet app for the [Ledger Nano S](https://shop.ledger.com/products/ledger-nano-s), [Ledger Nano S Plus](https://shop.ledger.com/pages/ledger-nano-s-plus) and [Ledger Nano X](https://shop.ledger.com/pages/ledger-nano-x) that makes it possible to store [DigitalBits](https://digitalbits.io/)-based assets on those devices and generally sign any transaction for the DigitalBits network.

## Documentation

This app follows the specification available in the [`./docs`](./docs/) folder.

## SDK

You can communicate with the app through the following libraries:

- [JavaScript library](https://github.com/xdbfoundation/digitalbits-ledger-api)

## Building and installing

If not for development purposes, you should install this app via [Ledger Live](https://www.ledger.com/ledger-live).

To build and install the app on your Nano S or Nano S Plus you must set up the Ledger build environments. Please follow [the load the application instructions](https://developers.ledger.com/docs/embedded-app/introduction/) at the Ledger developer portal.

Additionaly, install this dependency:

```shell
sudo apt install libbsd-dev
```

The command to compile and load the app onto the device is:

```shell
make load
```

To remove the app from the device do:

```shell
make delete
```

## Testing

This project provides unit tests, integration tests and end-to-end tests, unit tests are located under the [`./tests_unit`](./tests_unit) folder, and the integration tests and end-to-end tests are located under the [`./tests_zemu`](./tests_zemu) folder. 

During development, we recommend that you run the unit test first, as it takes less time to run, and then run the other tests after the unit test has run successfully.

### Unit testing

The `./tests_unit` directory contains files for testing the utils, the xdr transaction parser, the screen formatter and the swap function.

They require the [Node.js](https://nodejs.org/), [cmocka](https://cmocka.org/) unit testing framework, [CMake](https://cmake.org/) and [libbsd](https://libbsd.freedesktop.org/wiki/) to be installed:

```shell
sudo apt install libcmocka-dev cmake libbsd-dev
```

It is recommended to use [nvm](https://github.com/nvm-sh/nvm) to install the latest LTS version of Node.js

To build and execute the tests, run the following command:

```shell
make tests-unit
```

### Integration testing and end-to-end testing
Testing is done via the open-source framework [zemu](https://github.com/Zondax/zemu).

In order to run these tests, you need to install [Docker](https://www.docker.com/) in addition to the dependencies mentioned in *Unit testing*.

To build and execute the tests, run the following commands:

```shell
make tests-zemu
```

To run a specific test first, please run the following commands:

```shell
cd tests_zemu
npm run test -- -t "{testCaseName}"
```
