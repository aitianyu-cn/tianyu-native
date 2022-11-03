/**@format */

const { generateCMake } = require("./common/build");
const prebuild = require("./common/prebuild");
const { printStart } = require("./common/utils");

function getStartPrintInserts() {
    const startPrintInsert = [];

    startPrintInsert.push(`Build Type: native`);

    return startPrintInsert;
}

// run all jobs
function run() {
    const inserts = getStartPrintInserts();
    printStart(inserts);

    console.log(`\x1B[34mPROGRESS START\x1B[0m`);
    console.log();
    console.log(`\x1B[33m*******************************************************\x1B[0m`);
    console.log();

    prebuild
        .run()
        .then(
            () => {
                console.log(`\x1B[33m*******************************************************\x1B[0m`);
                console.log();
                console.log(`\x1B[34m # Build Start \x1B[0m`);
                console.log();

                try {
                    generateCMake("TEST");

                    console.log(`\x1B[32m # Build Successful \x1B[0m`);
                } catch (e) {
                    console.log(`\x1B[31m # Build Failed ${e.toString()} \x1B[0m`);
                }
            },
            (reason) => {
                //
            },
        )
        .finally(() => {
            console.log();
            console.log(`\x1B[33m*******************************************************\x1B[0m`);
            console.log();
            console.log(`\x1B[34mPROGRESS END\x1B[0m`);
        });
}

// run
run();
