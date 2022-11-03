/**@format */

const fs = require("fs");
const path = require("path");

const definition = require("./common/define");
const buildHelper = require("./common/buildHelper");

// pre-jobs import
const buildI18n = require("./common/i18n");
const { fileExists, StringHelper } = require("./common/utils");

// pre-jobs done
const aPrePromises = [];
aPrePromises.push(buildI18n.build(definition.BUILD_LANGUAGE));

/**
 * @type {{source:string;target:string;header:string[];}[]}
 */
const aTargetHeaderList = [];

// generate cmake file
function generateCMake() {
    const cmakeFile = path.resolve(definition.PROJECT_BASE_PATH, "CMakeLists.txt");

    const aLibContent = [];

    aLibContent.push("");
    const libSource = definition.configure.test.libs;
    const libraries = buildHelper.generateLibaries(libSource);
    for (const library of libraries) {
        const libContent = buildHelper.prepareLibsContent(library, aTargetHeaderList);
        aLibContent.push(...libContent);
    }

    aLibContent.push("");
    const testCases = buildHelper.generateTestBinaries();
    for (const testCase of testCases) {
        const testContent = buildHelper.prepareBinContent(testCase);
        aLibContent.push(...testContent);
    }

    const content = buildHelper.prepareCMakeContent(aLibContent);
    fs.writeFileSync(cmakeFile, content, { encoding: "utf-8" });
}

// run all jobs
function run() {
    Promise.all(aPrePromises).then(
        () => {
            generateCMake();
        },
        (reason) => {
            //
        },
    );
}

// run
run();