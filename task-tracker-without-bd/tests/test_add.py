
async def test_correct_json_add(service_client):
    request_json = {
        "title": "firsttask",
        "description": "do smth",
        "status": "new"
    } 

    response = await service_client.post(
        '/add',
        json=request_json,
    )

    assert response.status == 200
    data = response.json()

    assert data['title'] == 'firsttask'
    assert data['description'] == 'do smth'
    assert data['status'] == 'new'
    assert 'id' in data


import pytest

async def test_add_invalid_json(service_client):
    invalid_json_body = '{"title": "task1", "description": "do smth", "status": "new"'

    response = await service_client.post(
        '/add',
        data=invalid_json_body,
        headers={'Content-Type': 'application/json'}
    )

    assert response.status == 400

    data = response.json()
    assert 'code' in data
    assert data['code'] == '400'
    assert 'message' in data
    assert 'Invalid JSON body' in data['message']

async def test_add_missing_fields(service_client):
    request_json = {"title": "task1"}

    response = await service_client.post(
        '/add',
        json=request_json,
    )

    assert response.status == 400

    data = response.json()
    assert 'code' in data
    assert data['code'] == '400'

async def test_add_empty_fields(service_client):
    request_json = {
        "title": "",
        "description": "",
        "status": ""
    }

    response = await service_client.post(
        '/add',
        json=request_json
    )

    assert response.status in (200, 400)