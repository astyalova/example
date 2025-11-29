
async def test_correct_empty_storage_get_request(service_client):
    response = await service_client.get('/get')

    assert response.status == 200
    data = response.json()
    assert isinstance(data, list)

async def test_add_task_and_get(service_client):

    task_data = {
        "title": "My task",
        "description": "Test description",
        "status": "todo"
    }

    response = await service_client.post(
        '/add',
        json=task_data
    )

    assert response.status == 200
    created_task = response.json()
    assert 'id' in created_task
    assert created_task['title'] == task_data['title']

    response = await service_client.get('/get')
    assert response.status == 200
    data = response.json()

    task_ids = [task['id'] for task in data]
    assert created_task['id'] in task_ids

