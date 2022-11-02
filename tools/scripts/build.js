/**@format */

const path = require("path");

const buildConfiguration = require("../../config/build.json");

const PROJECT_BASE_PATH = path.resolve(__dirname, "../..");
const PROJECT_SOURCE_ENTRY = path.resolve(PROJECT_BASE_PATH, buildConfiguration.baseURL);
const PROJECT_BUILD_TARGET = path.resolve(PROJECT_BASE_PATH, buildConfiguration.output);
