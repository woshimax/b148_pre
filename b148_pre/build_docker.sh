#!/bin/bash
NAMESPACE="${1:-codebase_b148_app}"
docker build -t "$NAMESPACE" .